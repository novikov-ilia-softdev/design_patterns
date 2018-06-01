#include <iostream>

class IAdapter {
public:
	virtual void request() { std::cout << "IAdapter::request" << std::endl; }
};

class Adaptee {
public:
	void specificRequest() { std::cout << "Adaptee::specificRequest" << std::endl; }
};

class Adapter: public IAdapter {
public:
	Adapter() { adaptee_ = new Adaptee(); }
	void request() { adaptee_->specificRequest(); }

private:
	Adaptee* adaptee_;
};

int main()
{
	IAdapter* adapter = new Adapter;
	adapter->request();
}
