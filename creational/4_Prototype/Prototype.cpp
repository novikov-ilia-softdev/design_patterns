// Паттерн "Prototype"

#include <iostream>
using namespace std;

class AbstractProrotype {
public:
	virtual ~AbstractProrotype() {}
	virtual AbstractProrotype* clone() const = 0;
};

class ConcreteProrotype1 : public AbstractProrotype {
public:
	ConcreteProrotype1* clone() const { return new ConcreteProrotype1( *this ); }
};

class ConcreteProrotype2 : public AbstractProrotype {
public:
	ConcreteProrotype2* clone() const { return new ConcreteProrotype2( *this ); }
};

int main()
{

	system("pause");
}