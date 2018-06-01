// Паттерн "Visitor"

#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;

// Абстрактный посетитель
class Visitor {
public:
	virtual void VisitConcreteElementA( ConcreteElementA* pA ) = 0;
	virtual void VisitConcreteElementB( ConcreteElementB* pB ) = 0;
	virtual ~Visitor() {}
};

// Конкретный посетитель1
class ConcreteVisitor1: public Visitor {
public:
	virtual void VisitConcreteElementA( ConcreteElementA* pA )
	{
		cout << "ConcreteVisitor1::VisitConcreteElementA" << endl;
	}
	virtual void VisitConcreteElementB( ConcreteElementB* pB )
	{
		cout << "ConcreteVisitor1::VisitConcreteElementB" << endl;
	}
};

// Конкретный посетитель2
class ConcreteVisitor2: public Visitor {
public:
	virtual void VisitConcreteElementA( ConcreteElementA* pA )
	{
		cout << "ConcreteVisitor2::VisitConcreteElementA" << endl;
	}
	virtual void VisitConcreteElementB( ConcreteElementB* pB )
	{
		cout << "ConcreteVisitor2::VisitConcreteElementB" << endl;
	}
};

// Абстрактный элемент
class Element {
public:
	virtual void Accept( Visitor* pV ) = 0;
	virtual ~Element() {} 
};

// Конкретный элемент A
class ConcreteElementA: public Element {
public:
	virtual void Accept( Visitor* pV )
	{
		pV->VisitConcreteElementA( this );
	}
	void OperationA() { cout << "ConcreteElementA::OperationA" << endl; }
};

// Конкретный элемент B
class ConcreteElementB: public Element {
public:
	virtual void Accept( Visitor* pV )
	{
		pV->VisitConcreteElementB( this );
	}
	void OperationB() { cout << "ConcreteElementA::OperationB" << endl; }
};

// Класс содержит функцию, которая служит 3-им параметром
// в алгоритме for_each
// Освобождение памяти по указателю
class GarbageColector {
public:
	static void FreeMemory(Element* in)
	{
		delete in;
	}
};

int main( int argc, char* argv[] )
{
	// Создаем структуру элементов
	vector<Element*> elements;
	Element* pA = new ConcreteElementA;
	Element* pB = new ConcreteElementB;
	elements.push_back( pA );
	elements.push_back( pB );

	// Создаем посетителя1
	Visitor* v1 = new ConcreteVisitor1;
	
	// Посещаем все элементы структуры посетителем1
	vector<Element*>::iterator it;
	for ( it = elements.begin(); it != elements.end(); it++ )
	{
		(*it)->Accept( v1 );
	}

	// Создаем посетителя2
	Visitor* v2 = new ConcreteVisitor2;
	// Посещаем все элементы структуры посетителем2
	for ( int i = 0; i < elements.size(); i++ )
	{
		elements[i]->Accept( v2 );
	}

	// Освобождаем выделенную память
	delete v1;
	delete v2;
	for_each( elements.begin(), elements.end(), GarbageColector::FreeMemory );
	elements.clear();
	
	cout << endl;
	system("pause");
	return 0; 
}