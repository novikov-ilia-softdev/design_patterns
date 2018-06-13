#include <iostream>

class Memento;

class Originator {
public:
	std::string getState() const { return state_; }
	void setState( const std::string& str )
	{
		state_ = str;
		showState();
	}
	void showState() const { std::cout << "State = " << state_ << std::endl; }
	Memento* createMemento();
	void setMemento( const Memento& memento );
private:
	std::string state_;
};

class Memento {
private:
	friend class Originator;
	Memento( const std::string& state ) { this->state_ = state; }
	std::string getState() const { return state_; }
	std::string state_;
};

class Caretaker {
public:
	Caretaker( const Memento& memento): memento_( memento) {}
	Memento getMemento() const { return memento_; }
private:
	const Memento& memento_;
};

Memento* Originator::createMemento()
{
	return ( new Memento( state_) );
}

void Originator::setMemento( const Memento& memento )
{
	std::cout << "Restoring state..." << std::endl;
	state_ = memento.getState();
}

int main()
{
	Originator originator;
	originator.setState("On");
	Caretaker caretaker( *( originator.createMemento()));
	originator.setState( "Off" );
	originator.setMemento( caretaker.getMemento());
	originator.showState();
}
