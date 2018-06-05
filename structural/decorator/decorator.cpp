#include <iostream>
#include <memory>

class IComponent {
public:
	virtual void operation() = 0;
	virtual ~IComponent(){}
};

class Component : public IComponent {
public:
	virtual void operation() { std::cout << "World!" << std::endl; }
};

class IDecorator: public IComponent {
public:
	IDecorator( IComponent* component): component_(component) {}
	virtual void operation() = 0;
	virtual ~IDecorator() {}
protected:
	std::auto_ptr<IComponent> component_;
};

class DecoratorOne : public IDecorator {
public:
	DecoratorOne( IComponent* component): IDecorator(component) {}
	virtual void operation() { std::cout << ", "; component_->operation();}
};

class DecoratorTwo : public IDecorator {
public:
	DecoratorTwo( IComponent* component): IDecorator(component) {}
	virtual void operation() { std::cout << "Hello"; component_->operation(); }
};

int main()
{
	IDecorator* dec = new DecoratorTwo( new DecoratorOne( new Component()));
	dec->operation(); // Hello, World!
}
