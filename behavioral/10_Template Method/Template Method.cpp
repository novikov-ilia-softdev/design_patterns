// Паттерн "Template Method"

#include <iostream>
using namespace std;

class AbstractClass {
public:
	void TemplateMethod()
	{
		// Идиома NVI - невиртуальный интерфейс
		cout << "Preparing..." << endl;
		PrimitiveOperation1();
		cout << "Checking..." << endl;
		PrimitiveOperation2();
		cout << "Finishing..." << endl;
	}
	virtual ~AbstractClass() = 0 { cout << "~AbstractClass" << endl; }

private:
	virtual void PrimitiveOperation1() 
	{
		cout << "AbstractClass::PrimitiveOperation1" << endl;
	}
	virtual void PrimitiveOperation2() 
	{
		cout << "AbstractClass::PrimitiveOperation2" << endl;
	}
};

class ConcreteClass: public AbstractClass {
public:
	virtual ~ConcreteClass() { cout << "~ConcreteClass" << endl; }

private:
	virtual void PrimitiveOperation1() 
	{
		cout << "ConcreteClass::PrimitiveOperation1" << endl;
	}
	virtual void PrimitiveOperation2()
	{
		cout << "ConcreteClass::PrimitiveOperation2" << endl;
	}
};

int main( int argc, char* argv[] )
{
	AbstractClass* ptr = new ConcreteClass;

	ptr->TemplateMethod();

	cout << endl;
	cout << "Free resources..." << endl;
	delete ptr;

	cout << endl;
	system("pause");
	return 0; 
}