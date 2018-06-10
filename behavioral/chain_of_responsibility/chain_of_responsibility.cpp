#include <iostream>

class IChainOfResponsibility{
public:
	virtual void process( int i) = 0;
	void setNext( IChainOfResponsibility* next){ next_ = next; }
	virtual ~IChainOfResponsibility() {}
	
protected:
	IChainOfResponsibility* next_;
};

class PositiveNumberHandler: public IChainOfResponsibility{
public:
	void process( int i) 
	{ 
		if( i > 0)
			std::cout << "Positive" << std::endl;
		else
			next_->process( i);
	}
};

class NegativeNumberHandler: public IChainOfResponsibility{
public:
	void process( int i) 
	{ 
		if( i < 0)
			std::cout << "Negative" << std::endl;
		else
			next_->process( i);
	}
};

class ZeroNumberHandler: public IChainOfResponsibility{
public:
	void process( int i) 
	{ 
		if( i == 0)
			std::cout << "Zero" << std::endl;
		else
			next_->process( i);
	}
};

int main()
{
	IChainOfResponsibility* chain = new PositiveNumberHandler();
	IChainOfResponsibility* second = new NegativeNumberHandler();
	IChainOfResponsibility* third = new ZeroNumberHandler();
	
	chain->setNext( second);
	second->setNext( third);
	
	chain->process( 1);
	chain->process( -1);
	chain->process( 0);
	
	delete chain;
	delete second;
	delete third;
}