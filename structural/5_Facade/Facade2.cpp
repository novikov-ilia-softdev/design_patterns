// Паттерн "Facade"

#include <iostream>
#include <memory>
#include <string>
using namespace std;

namespace Library {

	class SubSystemA{
	public:
		static string A1()
		{
			return "SubSystemA, Method A1\n";
		}
		static string A2()
		{
			return "SubSystemA, Method A2\n";
		}
	};

	class SubSystemB{
	public:
		static string B1()
		{
			return "SubSystemB, Method B1\n";
		}
	};

	class SubSystemC{
	public:
		static string C1()
		{
			return "SubSystemC, Method C1\n";
		}
	};
}

class Facade {
public:
	typedef Library::SubSystemA SysA;
	typedef Library::SubSystemB SysB;
	typedef Library::SubSystemC SysC;

	void Operation1()
	{
		cout << "Operation1:\n" + SysA::A1() + SysA::A2() + SysB::B1() << endl;
	}

	void Operation2()
	{
		cout << "Operation2:\n" + SysB::B1() + SysC::C1() << endl;
	}
};

int main()
{
	Facade facade;
	facade.Operation1();
	cout << endl;
	facade.Operation2();

	system("pause");
}