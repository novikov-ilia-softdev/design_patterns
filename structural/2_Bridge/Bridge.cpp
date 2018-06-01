// ������� "Bridge"

#include <iostream>
using namespace std;

// ����������� ����������
class Implementor {
public:
	virtual void OperationImpl() = 0;
	virtual ~Implementor() {}
};

// ���������� ���������� A
class ConcreteImplementorA: public Implementor {
public:
	void OperationImpl() { cout << "ConcreteImplementorA" << endl; }
};

// ���������� ���������� B
class ConcreteImplementorB: public Implementor {
public:
	void OperationImpl() { cout << "ConcreteImplementorB" << endl; }
};

// ����������� ����������
class Abstraction {
protected:
	Implementor* pimpl;
	
public:
	Implementor* get() const { return pimpl; }
	void set(Implementor* p) { pimpl = p; }
	virtual void Operation() = 0;
	virtual ~Abstraction() {}
};

// ���������� ����������
class RefineAbstraction: public Abstraction {
public:
	void Operation() { pimpl->OperationImpl(); }
};

int main()
{
	Abstraction* ab = new RefineAbstraction;

	// ������������� ���������� � ��������
	Implementor* pimplA = new ConcreteImplementorA;
	ab->set(pimplA);
	ab->Operation();
	delete pimplA;

	// ������ ���������� � ��������
	Implementor* pimplB = new ConcreteImplementorB;
	ab->set(pimplB);
	ab->Operation();
	delete pimplB;

	delete ab;

	system("pause");
}