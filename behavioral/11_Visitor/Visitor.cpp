// ������� "Visitor"

#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;

// ����������� ����������
class Visitor {
public:
	virtual void VisitConcreteElementA( ConcreteElementA* pA ) = 0;
	virtual void VisitConcreteElementB( ConcreteElementB* pB ) = 0;
	virtual ~Visitor() {}
};

// ���������� ����������1
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

// ���������� ����������2
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

// ����������� �������
class Element {
public:
	virtual void Accept( Visitor* pV ) = 0;
	virtual ~Element() {} 
};

// ���������� ������� A
class ConcreteElementA: public Element {
public:
	virtual void Accept( Visitor* pV )
	{
		pV->VisitConcreteElementA( this );
	}
	void OperationA() { cout << "ConcreteElementA::OperationA" << endl; }
};

// ���������� ������� B
class ConcreteElementB: public Element {
public:
	virtual void Accept( Visitor* pV )
	{
		pV->VisitConcreteElementB( this );
	}
	void OperationB() { cout << "ConcreteElementA::OperationB" << endl; }
};

// ����� �������� �������, ������� ������ 3-�� ����������
// � ��������� for_each
// ������������ ������ �� ���������
class GarbageColector {
public:
	static void FreeMemory(Element* in)
	{
		delete in;
	}
};

int main( int argc, char* argv[] )
{
	// ������� ��������� ���������
	vector<Element*> elements;
	Element* pA = new ConcreteElementA;
	Element* pB = new ConcreteElementB;
	elements.push_back( pA );
	elements.push_back( pB );

	// ������� ����������1
	Visitor* v1 = new ConcreteVisitor1;
	
	// �������� ��� �������� ��������� �����������1
	vector<Element*>::iterator it;
	for ( it = elements.begin(); it != elements.end(); it++ )
	{
		(*it)->Accept( v1 );
	}

	// ������� ����������2
	Visitor* v2 = new ConcreteVisitor2;
	// �������� ��� �������� ��������� �����������2
	for ( int i = 0; i < elements.size(); i++ )
	{
		elements[i]->Accept( v2 );
	}

	// ����������� ���������� ������
	delete v1;
	delete v2;
	for_each( elements.begin(), elements.end(), GarbageColector::FreeMemory );
	elements.clear();
	
	cout << endl;
	system("pause");
	return 0; 
}