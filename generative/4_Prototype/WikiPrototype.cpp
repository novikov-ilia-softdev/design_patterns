// Паттерн "Prototype"

#include <iostream>
#include <assert.h>
using namespace std;

// AbstractProrotype
class AbstractProrotype {
public:
	AbstractProrotype(int i): m_num(i) {}
	virtual ~AbstractProrotype() {}
	virtual AbstractProrotype* clone() const = 0;

	int getNum() const { return m_num; }

private:
	int m_num;

};

// ConcreteProrotype1
class ConcreteProrotype1 : public AbstractProrotype {
public:
	ConcreteProrotype1(int i): AbstractProrotype(i) {}
	ConcreteProrotype1* clone() const { return new ConcreteProrotype1( *this ); }
};

// ConcreteProrotype2
class ConcreteProrotype2 : public AbstractProrotype {
public:
	ConcreteProrotype2(int i): AbstractProrotype(i) {}
	ConcreteProrotype2* clone() const { return new ConcreteProrotype2( *this ); }
};

int main()
{
	// Создаем прототип
	AbstractProrotype* p1 = new ConcreteProrotype1(5);
	
	// Создаем объект на основе прототипа 
	AbstractProrotype* c1 = p1->clone();

	// Проверяем
	assert( p1->getNum() == c1->getNum() );

	AbstractProrotype* p2 = new ConcreteProrotype1(7);
	AbstractProrotype* c2 = p2->clone();
	assert( p2->getNum() == c2->getNum() );

	delete p1;
	delete c1;
	delete p2;
	delete c2;

	system("pause");
}