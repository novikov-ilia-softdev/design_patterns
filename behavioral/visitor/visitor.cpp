#include <iostream>
#include <vector>
#include <algorithm>

class ConcreteElementA;
class ConcreteElementB;

class IVisitor {
public:
	virtual void visitConcreteElementA( ConcreteElementA* pA ) = 0;
	virtual void visitConcreteElementB( ConcreteElementB* pB ) = 0;
	virtual ~IVisitor() {}
};

class ConcreteVisitor1: public IVisitor {
public:
	void visitConcreteElementA( ConcreteElementA* pA ){ std::cout << "ConcreteVisitor1::visitConcreteElementA" << std::endl; }
	void visitConcreteElementB( ConcreteElementB* pB ){ std::cout << "ConcreteVisitor1::visitConcreteElementB" << std::endl; }
};

class ConcreteVisitor2: public IVisitor {
public:
	void visitConcreteElementA( ConcreteElementA* pA ){ std::cout << "ConcreteVisitor2::visitConcreteElementA" << std::endl; }
	void visitConcreteElementB( ConcreteElementB* pB ){ std::cout << "ConcreteVisitor2::visitConcreteElementB" << std::endl; }
};

class IElement {
public:
	virtual void accept( IVisitor* pV ) = 0;
	virtual ~IElement() {}
};

class ConcreteElementA: public IElement {
public:
	void accept( IVisitor* pV ){ pV->visitConcreteElementA( this ); }
	void operationA() { std::cout << "ConcreteElementA::operationA" << std::endl; }
};

class ConcreteElementB: public IElement {
public:
	void accept( IVisitor* pV ){ pV->visitConcreteElementB( this );}
	void operationB() { std::cout << "ConcreteElementA::operationB" << std::endl; }
};

class GarbageColector {
public:
	static void freeMemory(IElement* in){ delete in; }
};

int main( int argc, char* argv[] )
{
	std::vector<IElement*> elements;
	IElement* pA = new ConcreteElementA;
	IElement* pB = new ConcreteElementB;
	elements.push_back( pA );
	elements.push_back( pB );

	IVisitor* v1 = new ConcreteVisitor1;
	
	std::vector<IElement*>::iterator it;
	for ( it = elements.begin(); it != elements.end(); it++ )
	{
		(*it)->accept( v1 );
	}

	IVisitor* v2 = new ConcreteVisitor2;
	for ( int i = 0; i < elements.size(); i++ )
	{
		elements[i]->accept( v2 );
	}

	delete v1;
	delete v2;
	for_each( elements.begin(), elements.end(), GarbageColector::freeMemory);
	elements.clear();
}
