#include <iostream>

class Context;

class IState {
public:
	virtual void handle( Context* pctx) = 0;
	virtual ~IState() {}
};

class Context {
public:
	Context( IState* state): _state( state) {}
	void request(){ _state->handle( this); }
	void setState( IState* state) { _state = state; }
	void deletePreviousState() { delete _state; }
	~Context() { delete _state; }
private:
	IState* _state;
};

class ConcreteStateA: public IState {
public:
	void handle( Context* pctx);
};

class ConcreteStateB: public IState {
public:
	void handle( Context* pctx);
};

class ConcreteStateC: public IState {
public:
	void handle( Context* pctx);
};

void ConcreteStateA::handle( Context* pctx)
{
	std::cout << "ConcreteStateA" << std::endl;
	pctx->deletePreviousState();
	pctx->setState( new ConcreteStateB);
}

void ConcreteStateB::handle( Context* pctx)
{
	std::cout << "ConcreteStateB" << std::endl;
	pctx->deletePreviousState();
	pctx->setState( new ConcreteStateC);
}

void ConcreteStateC::handle( Context* pctx)
{
	std::cout << "ConcreteStateC" << std::endl;
	pctx->deletePreviousState();
	pctx->setState( new ConcreteStateA);
}

int main( int argc, char* argv[] )
{
	IState* state = new ConcreteStateA;
	Context context( state);
	
	char ch;

	while( std::cin >> ch)
	{
		context.request();
	}
}
