#include <iostream>

class AbstractClass {
public:
	void templateMethod()
	{
		std::cout << "Preparing..." << std::endl;
		primitiveOperation1();
		std::cout << "Checking..." << std::endl;
		primitiveOperation2();
		std::cout << "Finishing..." << std::endl;
	}
	virtual ~AbstractClass(){ std::cout << "~AbstractClass" << std::endl; };
private:
	virtual void primitiveOperation1() = 0;
	virtual void primitiveOperation2() = 0;
};

class ConcreteClass: public AbstractClass {
public:
	virtual ~ConcreteClass() { std::cout << "~ConcreteClass" << std::endl; }
private:
	void primitiveOperation1(){ std::cout << "ConcreteClass::primitiveOperation1" << std::endl; }
	void primitiveOperation2(){ std::cout << "ConcreteClass::primitiveOperation2" << std::endl; }
};

int main( int argc, char* argv[] )
{
	AbstractClass* ptr = new ConcreteClass;
	ptr->templateMethod();
	std::cout << "Free resources..." << std::endl;
	delete ptr;
}
