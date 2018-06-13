#include <iostream>

class IColleague;

class IMediator{
public:
	virtual void send( const std::string& message, IColleague *fromColleague) = 0;
	virtual ~IMediator(){}
	virtual void setColleague1( IColleague* c ) = 0;
	virtual void setColleague2( IColleague* c ) = 0;
};

class IColleague{
public:
	IColleague( IMediator* mediator): mediator_( mediator) {}
	virtual ~IColleague(){}
	virtual void send( const std::string& message) { mediator_->send( message, this); }
	virtual void notify( const std::string& message) = 0;
protected:
	IMediator *mediator_;
};

class ConcreteColleague1 : public IColleague{
public:
	ConcreteColleague1( IMediator* mediator) : IColleague( mediator ) {}
	void notify( const std::string& message ) { std::cout << "Colleague1 gets message " << message.c_str() << std::endl; }
};

class ConcreteColleague2 : public IColleague{
public:
	ConcreteColleague2( IMediator *mediator) : IColleague(mediator){}
	void notify( const std::string& message) { std::cout << "Colleague2 gets message " << message.c_str() << std::endl; }
};

class ConcreteMediator : public IMediator{
public:
	void setColleague1( IColleague* c) { colleague1_ = c;}
	void setColleague2( IColleague* c){ colleague2_ = c;}

	void send( const std::string& message, IColleague *fromColleague)
	{
		if( fromColleague == colleague1_ )
		{
			colleague2_->notify( message );
			return;
		}
		if ( fromColleague == colleague2_ )
		{
			colleague1_->notify( message );
			return;
		}
	}
private:
	IColleague* colleague1_;
	IColleague* colleague2_;
};

int main()
{
	std::string question( "How are you?");
	std::string answer( "Fine, thanks!");

	IMediator* m = new ConcreteMediator();

	IColleague* c1 = new ConcreteColleague1( m);
	IColleague* c2 = new ConcreteColleague2( m);

	m->setColleague1( c1 );
	m->setColleague2( c2 );

	c1->send( question);
	c2->send( answer);
}
