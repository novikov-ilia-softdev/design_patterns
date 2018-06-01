// Паттерн "Observer"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SupervisedString;

// IObserver
class IObserver {
public:
	virtual void Update( const SupervisedString& ) = 0;
};

// ISubject
class ISubject {
public:
	virtual void Add( IObserver& ref )		= 0;
	virtual void Remove( IObserver& ref )	= 0;

private:
	virtual void _Notify()					= 0;
};

// ConcreteSubject
class SupervisedString: public ISubject { // Observable class
public:
	virtual void Add( IObserver& ref )
	{
		_observers.push_back( item( &ref ) );
	}

	virtual void Remove( IObserver& ref )
	{
		vector<IObserver* const>::iterator it;
		bool bFound = false;
		for ( it = _observers.begin(); it != _observers.end(); it++ )
		{
			if ( *it == item( &ref ) )
			{
				_observers.erase(it);
				bFound = true;
				break;
			}
		}
		if ( !bFound )
		{
			cout << "There is no IObserber to delete!" << endl;
		}
	}

	const string Get() const
	{
		return _str;
	}

	void Set( string str )
	{
		_str = str;
		_Notify();
	}

private:
	string _str;
	vector<IObserver* const> _observers;

	typedef vector<IObserver* const>::value_type item;

	virtual void _Notify()
	{
		vector<IObserver* const>::iterator it;
		for ( it = _observers.begin(); it != _observers.end(); it++ )
		{
			(*it)->Update( *this );
		}
	}
};

// ConcreteObserver1
class Reflector: public IObserver { // Prints the observed string into std::cout
public:
	virtual void Update( const SupervisedString& ref )
	{
		cout << ref.Get() << endl;
	}
};

// ConcreteObserver2
class Counter: public IObserver {  // Prints the length of observed string into std::cout
	virtual void Update( const SupervisedString& ref )
	{
		cout << "length = " << ref.Get().length() << endl;
	}
};

int main()
{
	SupervisedString	str;
	Reflector			refl;
	Counter				cnt;

	str.Add( refl );
	str.Set("Hello, World!");
	cout << endl;

	str.Remove( refl );
	str.Add( cnt );
	str.Set("World, Hello!");
	cout << endl;

	system("pause");
	return 0; 
}