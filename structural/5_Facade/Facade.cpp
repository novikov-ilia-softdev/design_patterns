// Паттерн "Facade"

#include <iostream>
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
	static void Operation1()
	{
		//cout << "Operation1:\n" + Library::SubSystemA::A1() + m_pA->A2() + m_pB->B1() << endl;
		cout << "Operation1:\n" + m_pA->A1() + m_pA->A2() + m_pB->B1() << endl;
		
	}

	static void Operation2()
	{
		cout << "Operation2:\n" + m_pB->B1() + m_pC->C1() << endl;
	}

private:
	static Library::SubSystemA* m_pA;
	static Library::SubSystemB* m_pB;
	static Library::SubSystemC* m_pC;
};

int main()
{
	Facade::Operation1();
	cout << endl;
	Facade::Operation2();

	system("pause");
}