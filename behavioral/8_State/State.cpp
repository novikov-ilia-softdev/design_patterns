// Паттерн "State"

#include <iostream>
#include <conio.h>
using namespace std;

class Context;

class IState {
public:
	// Передаем указатель на Context,
	// чтобы State сам сменил его состояние,
	// как только отработает
	virtual void Handle( Context* pctx ) = 0;
	virtual ~IState() {}
};

class Context {
public:
	Context( IState* state ): _state(state) {}
	void Request() 
	{
		_state->Handle( this );
	}

	void SetState(IState* state) { _state = state; }
	void DeletePreviousState() { delete _state; }
	~Context() { delete _state; }

private:
	IState* _state;
};

class ConcreteStateA: public IState {
public:
	virtual void Handle( Context* pctx );
};

class ConcreteStateB: public IState {
public:
	virtual void Handle( Context* pctx );
};

class ConcreteStateC: public IState {
public:
	virtual void Handle( Context* pctx );
};

void ConcreteStateA::Handle( Context* pctx )
{
	cout << "ConcreteStateA" << endl;
	pctx->DeletePreviousState();
	pctx->SetState( new ConcreteStateB );
}

void ConcreteStateB::Handle( Context* pctx )
{
	cout << "ConcreteStateB" << endl;
	pctx->DeletePreviousState();
	pctx->SetState( new ConcreteStateC );
}

void ConcreteStateC::Handle( Context* pctx )
{
	cout << "ConcreteStateC" << endl;
	pctx->DeletePreviousState();
	pctx->SetState( new ConcreteStateA );
}

int main( int argc, char* argv[] )
{
	IState* state = new ConcreteStateA;
	Context context( state );
	
	while( !kbhit() )
	{
		context.Request();
	}

	cout << endl;
	system("pause");
	return 0; 
}