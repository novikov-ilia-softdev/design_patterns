// Паттерн "Chain of Responsibility"

#include <iostream>

class Colleague;

// Посредник
class IMediator
{
public:
	virtual void Send( std::string message, Colleague *colleague ) = 0;
	virtual ~IMediator(){}
};

// Сослуживец
class Colleague
{
protected:
	IMediator *mediator;
public:
	Colleague( IMediator *mediator )
	{
		this->mediator = mediator;
	}
	virtual ~Colleague(){}
};

class ConcreteColleague1:public Colleague
{
public:
	ConcreteColleague1( IMediator *mediator ):Colleague( mediator )
	{
	}

	void Send( std::string message )
	{
		mediator->Send( message, this );
	}

	void Notify( std::string message )
	{
		std::cout << "Colleague1 gets message " << message.c_str() << std::endl;
	}
};

class ConcreteColleague2:public Colleague
{
public:
	ConcreteColleague2(IMediator *mediator):Colleague(mediator)
	{
	}

	void Send(std::string message)
	{
		mediator->Send(message, this);
	}

	void Notify(std::string message)
	{
		std::cout << "Colleague2 gets message " << message.c_str() << std::endl;
	}
};

class ConcreteMediator:public IMediator
{
private:
	ConcreteColleague1*     m_Colleague1;
	ConcreteColleague2*     m_Colleague2;

public:
	void SetColleague1( ConcreteColleague1* c )
	{
		m_Colleague1 = c;
	}

	void SetColleague2( ConcreteColleague2* c )
	{
		m_Colleague2 = c;
	}

	virtual void Send( std::string message, Colleague *colleague )
	{
		if ( colleague == static_cast <Colleague*> ( m_Colleague1 ) )
		{
			m_Colleague2->Notify( message );
		}
		else if ( colleague == static_cast <Colleague*> ( m_Colleague2 ) )
		{
			m_Colleague1->Notify( message );
		}
	}
};

int main()
{
	ConcreteMediator* m = new ConcreteMediator();

	ConcreteColleague1* c1 = new ConcreteColleague1(m);
	ConcreteColleague2* c2 = new ConcreteColleague2(m);

	m->SetColleague1( c1 );
	m->SetColleague2( c2 );

	c1->Send( "How are you?" );
	c2->Send( "Fine, thanks!" );

	system("pause");
}