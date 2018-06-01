// Паттерн "Bridge"

#include <iostream>
using namespace std;

// Абстрактная реализация
class Implementor {
public:
	virtual void OperationImpl() = 0;
	virtual ~Implementor() {}
};

// Конкретная реализация A
class ConcreteImplementorA: public Implementor {
public:
	void OperationImpl() { cout << "ConcreteImplementorA" << endl; }
};

// Конкретная реализация B
class ConcreteImplementorB: public Implementor {
public:
	void OperationImpl() { cout << "ConcreteImplementorB" << endl; }
};

// Абстрактная абстракция
class Abstraction {
protected:
	Implementor* pimpl;
	
public:
	Implementor* get() const { return pimpl; }
	void set(Implementor* p) { pimpl = p; }
	virtual void Operation() = 0;
	virtual ~Abstraction() {}
};

// Уточненная абстракция
class RefineAbstraction: public Abstraction {
public:
	void Operation() { pimpl->OperationImpl(); }
};

int main()
{
	Abstraction* ab = new RefineAbstraction;

	// Устанавливаем реализацию и вызываем
	Implementor* pimplA = new ConcreteImplementorA;
	ab->set(pimplA);
	ab->Operation();
	delete pimplA;

	// Меняем реализацию и вызываем
	Implementor* pimplB = new ConcreteImplementorB;
	ab->set(pimplB);
	ab->Operation();
	delete pimplB;

	delete ab;

	system("pause");
}