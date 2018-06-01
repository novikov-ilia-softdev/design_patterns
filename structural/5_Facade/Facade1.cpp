// Паттерн "Facade"

#include <iostream>
#include <memory>
#include <string>
using namespace std;

namespace Library {

	class SubSystemA{
	public:
		string A1()
		{
			return "SubSystemA, Method A1\n";
		}
		string A2()
		{
			return "SubSystemA, Method A2\n";
		}
	};

	class SubSystemB{
	public:
		string B1()
		{
			return "SubSystemB, Method B1\n";
		}
	};

	class SubSystemC{
	public:
		string C1()
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
		cout << "Operation1:\n" + m_pA->A1() + m_pA->A2() + m_pB->B1() << endl;
	}

	void Operation2()
	{
		cout << "Operation2:\n" + m_pB->B1() + m_pC->C1() << endl;
	}

private:
	shared_ptr<SysA> m_pA;
	shared_ptr<SysB> m_pB;
	shared_ptr<SysC> m_pC;
};

int main()
{
	Facade facade;
	facade.Operation1();
	cout << endl;
	facade.Operation2();

	system("pause");
}