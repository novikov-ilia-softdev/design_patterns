#include <iostream>

class IStrategy{
public:
	virtual ~IStrategy(){}
	virtual void use() = 0;
};

class Strategy1: public IStrategy{
public:
	void use(){ std::cout << "Strategy1" << std::endl; };
};

class Strategy2: public IStrategy{
public:
	virtual void use(){ std::cout << "Strategy2" << std::endl; };
};

class Strategy3: public IStrategy{
public:
	virtual void use(){ std::cout << "Strategy3" << std::endl; };
};

class IContext{
protected:
	IStrategy* operation_;
public:
	virtual void useStrategy() = 0;
	virtual void setStrategy( IStrategy* v) = 0;
	virtual ~IContext() {}
};

class Client: public IContext{
public:
	virtual void useStrategy() { operation_->use(); }
	void setStrategy( IStrategy* s ) { operation_ = s; }
};

int main()
{
	IContext* client = new Client;
	
	IStrategy* str1 = new Strategy1;
	IStrategy* str2 = new Strategy2;
	IStrategy* str3 = new Strategy3;

	client->setStrategy( str1);
	client->useStrategy();
	client->setStrategy( str2);
	client->useStrategy();
	client->setStrategy( str3);
	client->useStrategy();

	delete client;
	delete str1;
	delete str2;
	delete str3;
}
