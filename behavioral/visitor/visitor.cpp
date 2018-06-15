#include <iostream>

class IColor{
public:
    virtual void accept( class IVisitor*) = 0;
    virtual ~IColor() {}
};

class Red: public IColor{
public:
    void accept( IVisitor*);
    void eye(){ std::cout << "Red::eye" << std::endl;}
};

class Blu: public IColor{
public:
    void accept( IVisitor*);
    void sky(){ std::cout << "Blu::sky" << std::endl;}
};

class IVisitor{
public:
    virtual void visit( Red*) = 0;
    virtual void visit( Blu*) = 0;
    virtual ~IVisitor() {}
};

class CountVisitor: public IVisitor{
public:
    CountVisitor(): numRed_( 0), numBlu_( 0) {}
    void visit( Red*){ ++numRed_; }
    void visit( Blu*){ ++numBlu_; }
    void reportNum(){ std::cout << "Reds " << numRed_ << ", Blus " << numBlu_ << std::endl; }
private:
    int numRed_, numBlu_;
};

class CallVisitor: public IVisitor{
public:
    void visit( Red *r){ r->eye(); }
    void visit( Blu *b){ b->sky(); }
};

void Red::accept( IVisitor *v){ v->visit( this); }
void Blu::accept( IVisitor *v){ v->visit( this); }

int main()
{
	IColor *set[] = { new Red, new Blu, new Blu, new Red, new Red, 0};
	CountVisitor countOperation;
	CallVisitor callOperation;
	for( int i = 0; set[i]; i++)
	{
		set[i]->accept( &countOperation);
		set[i]->accept( &callOperation);
	}
	countOperation.reportNum();

	for( int i = 0; set[i]; i++)
	{
		delete set[i];
	}
}
