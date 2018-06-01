// Паттерн "Strategy"

#include <iostream>
using namespace std;

class Strategy
{
public:
	virtual ~Strategy(){}
	virtual void Use() = 0;
};

class Strategy_1: public Strategy
{
public:
	virtual void Use(){ cout << "Strategy_1" << endl; };
};

class Strategy_2: public Strategy
{
public:
	virtual void Use(){ cout << "Strategy_2" << endl; };
};

class Strategy_3: public Strategy
{
public:
	virtual void Use(){ cout << "Strategy_3" << endl; };
};

class Context
{
protected:
	Strategy* operation;

public:
	virtual void UseStrategy() = 0;
	virtual void SetStrategy( Strategy* v ) = 0;
	virtual ~Context() {}
};

class Client: public Context
{
public:
	virtual void UseStrategy()
	{
		operation->Use();
	}

	virtual void SetStrategy( Strategy* s )
	{
		operation = s;
	}
};

int main( int argc, char* argv[] )
{
	Client customClient;
	
	Strategy* str1 = new Strategy_1;
	Strategy* str2 = new Strategy_2;
	Strategy* str3 = new Strategy_3;

	customClient.SetStrategy( str1 );
	customClient.UseStrategy();
	customClient.SetStrategy( str2 );
	customClient.UseStrategy();
	customClient.SetStrategy( str3 );
	customClient.UseStrategy();

	delete str1;
	delete str2;
	delete str3;

	cout << endl;
	system("pause");
	return 0;
}