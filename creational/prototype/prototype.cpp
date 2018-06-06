#include <iostream>
#include <assert.h>

class IProrotype {
public:
	IProrotype( int i): num_(i) {}
	virtual ~IProrotype() {}
	virtual IProrotype* clone() const = 0;
	int getNum() const { return num_; }
private:
	int num_;
};

class ConcreteProrotype1 : public IProrotype {
public:
	ConcreteProrotype1( int i): IProrotype( i) {}
	ConcreteProrotype1* clone() const { return new ConcreteProrotype1( *this); }
};

class ConcreteProrotype2 : public IProrotype {
public:
	ConcreteProrotype2( int i): IProrotype( i) {}
	ConcreteProrotype2* clone() const { return new ConcreteProrotype2( *this) ; }
};

int main()
{
	IProrotype* p1 = new ConcreteProrotype1( 5);
	IProrotype* c1 = p1->clone();
	assert( p1->getNum() == c1->getNum());

	IProrotype* p2 = new ConcreteProrotype2( 7);
	IProrotype* c2 = p2->clone();
	assert( p2->getNum() == c2->getNum());

	delete p1;
	delete c1;
	delete p2;
	delete c2;
}
