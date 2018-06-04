#include <iostream>

class Implementor {
public:
	virtual void operationImpl() = 0;
	virtual ~Implementor() {}
};

class ConcreteImplementorA: public Implementor {
public:
	void operationImpl() { std::cout << "ConcreteImplementorA" << std::endl; }
};

class ConcreteImplementorB: public Implementor {
public:
	void operationImpl() { std::cout << "ConcreteImplementorB" << std::endl; }
};

class Abstraction {
protected:
	Implementor* pimpl;
	
public:
	Implementor* get() const { return pimpl; }
	void set(Implementor* p) { pimpl = p; }
	virtual void operation() = 0;
	virtual ~Abstraction() {}
};

class RefineAbstraction: public Abstraction {
public:
	void operation() { pimpl->operationImpl(); }
};

int main()
{
	Abstraction* ab = new RefineAbstraction;

	Implementor* pimplA = new ConcreteImplementorA;
	ab->set( pimplA);
	ab->operation();
	delete pimplA;

	Implementor* pimplB = new ConcreteImplementorB;
	ab->set( pimplB);
	ab->operation();
	delete pimplB;

	delete ab;
}
