#include <iostream>

class Singleton {
private:
	static Singleton s_;
	int i_;
	Singleton() {}
	Singleton( int x): i_(x) {}
	Singleton& operator = (Singleton&);
	Singleton (const Singleton&);

public:
	static Singleton& instance() { return s_; }
	int getValue() { return i_; }
	void setValue( int x) { i_ = x; }
};

Singleton Singleton::s_(47);

int main()
{
	Singleton& s1 = Singleton::instance();	
	std::cout << "s1.getValue() == " << s1.getValue() << std::endl;
	Singleton& s2 = Singleton::instance();
	std::cout << "s2.getValue() == " << s2.getValue() << std::endl << std::endl;
	std::cout << "s2.setValue(9)" << std::endl << std::endl;
	s2.setValue(9);
	std::cout << "s2.getValue() == " << s2.getValue() << std::endl;
	std::cout << "s1.getValue() == " << s1.getValue() << std::endl;
}
