// Паттерн "Interpreter"

#include <iostream>
#include <vector>
using namespace std;

class Context {};

class AbstractExpression {
public:
	virtual void Interpret( const Context& context ) = 0;
};

class TerminalExpression: public AbstractExpression {
public:
	virtual void Interpret( const Context& context )
	{
		cout << "Called TerminalExpression::Interpret" << endl;
	}
};

class NonTerminalExpression: public AbstractExpression {
public:
	virtual void Interpret( const Context& context )
	{
		cout << "Called NonTerminalExpression::Interpret" << endl;
	}
};

int main()
{
	const Context context;

	vector<AbstractExpression*> v;

	v.push_back( new (TerminalExpression) );
	v.push_back( new (NonTerminalExpression) );
	v.push_back( new (TerminalExpression) );
	v.push_back( new (TerminalExpression) );

	for( int i = 0; i < v.size(); i++ )
	{
		v[i]->Interpret( context );
	}

	system("pause");
	return 0; 
}