// Паттерн "Decorator"

#include <iostream>
#include <memory>

class IComponent {
public:
	virtual void operation() = 0;
	virtual ~IComponent(){}
};

class Component : public IComponent {
public:
	virtual void operation() {
		std::cout<<"World!"<<std::endl;
	}
};

class IDecorator: public IComponent {
public:
	IDecorator(IComponent* component): m_component(component) {}
	virtual void operation() = 0;
	virtual ~IDecorator() {}

protected:
	std::auto_ptr<IComponent> m_component;
};

class DecoratorOne : public IDecorator {
public:
	DecoratorOne(IComponent* component): IDecorator(component) {}

	virtual void operation() 
	{
		std::cout << ", ";
		m_component->operation();
	}
};

class DecoratorTwo : public IDecorator {
public:
	DecoratorTwo(IComponent* component): IDecorator(component) {}

	virtual void operation() 
	{
		std::cout << "Hello";
		m_component->operation();
	}
};

int main()
{
	DecoratorTwo obj( new DecoratorOne( new Component() ) );
	obj.operation(); // prints "Hello, World!\n"

	system("pause");
	return 0;
}