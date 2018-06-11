#include <iostream>

class Cat{
public:
	void appear() { std::cout << "Cat appeared" << std::endl; }
	void hide() { std::cout << "Cat hided" << std::endl; }
};

class ICommand{
public:
	ICommand( Cat *cat): cat_( cat) {}
	virtual void execute() = 0;
	virtual ~ICommand() {}
protected:
	Cat* cat_;
};

class SwitchOnCommand: public ICommand{
public:
	SwitchOnCommand( Cat *cat): ICommand( cat) {}
	void execute() { cat_->appear(); }
};

class SwitchOffCommand: public ICommand{
public:
	SwitchOffCommand( Cat *cat): ICommand( cat) {}
	void execute() { cat_->hide(); }
};

class Selector{
public:
	Selector( ICommand* up, ICommand* down): up_( up), down_( down) {}
	void switchOn() { up_->execute(); }
	void switchOff() { down_->execute(); }
private:
	ICommand* up_;
	ICommand* down_;
};


int main()
{
	Cat cat;

	ICommand* up = new SwitchOnCommand( &cat);
	ICommand* down = new SwitchOffCommand( &cat);

	Selector selector( up, down);

	selector.switchOn();
	selector.switchOff();

	delete up;
	delete down;
}
