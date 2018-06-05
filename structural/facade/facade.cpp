#include <iostream>

namespace Library {
	
	class SubSystemA{
	public:
		static void a1() { std::cout << "SubSystemA::a1" << std::endl; }
		static void a2() { std::cout << "SubSystemA::a2" << std::endl; }
	};

	class SubSystemB{
	public:
		static void b1() { std::cout << "SubSystemB::b1" << std::endl; }
	};

	class SubSystemC{
	public:
		static void c1() { std::cout << "SubSystemC::c1" << std::endl; }
	};
}

class Facade {
public:
	static void op1()
	{
		std::cout << "Facade::op1" << std::endl;
		Library::SubSystemA::a1();
		Library::SubSystemA::a2();
	}

	static void op2()
	{
		std::cout << "Facade::op2" << std::endl;
		Library::SubSystemB::b1();
		Library::SubSystemC::c1();
	}
};

int main()
{
	Facade::op1();
	Facade::op2();
}
