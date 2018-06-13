#include <iostream>
#include <vector>

class SupervisedString;

class IObserver {
public:
	virtual void update( const SupervisedString&) = 0;
};

class ISubject {
public:
	virtual void add( IObserver& ref) = 0;
	virtual void remove( IObserver& ref) = 0;
private:
	virtual void notify_() = 0;
};

class SupervisedString: public ISubject {
public:
	virtual void add( IObserver& ref ){ observers_.push_back( item( &ref ) );}
	virtual void remove( IObserver& ref )
	{
		std::vector<IObserver*>::iterator it;
		bool bFound = false;
		for ( it = observers_.begin(); it != observers_.end(); it++ )
		{
			if ( *it == item( &ref ) )
			{
				observers_.erase( it);
				bFound = true;
				break;
			}
		}
		if ( !bFound) { std::cout << "There is no IObserber to delete!" << std::endl; }
	}

	const std::string get() const{ return str_; }
	void set( std::string str ){ str_ = str; notify_(); }

private:
	std::string str_;
	std::vector<IObserver*> observers_;
	typedef std::vector<IObserver*>::value_type item;
	virtual void notify_()
	{
		std::vector<IObserver*>::iterator it;
		for ( it = observers_.begin(); it != observers_.end(); it++ )
		{
			( *it)->update( *this);
		}
	}
};

class Reflector: public IObserver {
public:
	void update( const SupervisedString& ref ){ std::cout << ref.get() << std::endl; }
};

class Counter: public IObserver {
	void update( const SupervisedString& ref ){ std::cout << "length = " << ref.get().length() << std::endl; }
};

int main()
{
	SupervisedString str;
	Reflector refl;
	Counter	cnt;

	str.add( refl );
	str.add( cnt );
	str.set("Hello, World!");

	str.remove( cnt );
	str.set("World, Helloooo!");
}
