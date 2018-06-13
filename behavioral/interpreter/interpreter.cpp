#include <iostream>

class Expression{
public:
	virtual bool interpret( std::string str) = 0;
};

class TerminalExpression: public Expression{
public:
	TerminalExpression( std::string str): str_( str) {}
	bool interpret( std::string str) { return str_.find( str) != std::string::npos;}
private:
	std::string str_;
};

class OrExpression: public Expression{
public:
	OrExpression( Expression* exp1, Expression* exp2): exp1_( exp1), exp2_( exp2) {}
	bool interpret( std::string str) { return exp1_->interpret( str) || exp2_->interpret( str);}
private:
	Expression* exp1_;
	Expression* exp2_;
};


int main(){
	Expression* person1 = new TerminalExpression( "Kushagra");
	Expression* person2 = new TerminalExpression( "Lokesh");
	Expression* isSingle = new OrExpression( person1, person2);

	std::cout << isSingle->interpret( "Kushagra") << std::endl;
	std::cout << isSingle->interpret( "Lokesh") << std::endl;
	std::cout << isSingle->interpret( "Achint") << std::endl;

	delete person1;
	delete person2;
	delete isSingle;
}
