// ������� "Adapter"

#include <iostream>
using namespace std;

// Target
class Target {
public:
	virtual void Request() { cout << "Called Target::Request" << endl; }
};

// Adaptee
class Adaptee {
public:
	void SpecificRequest() { cout << "Called Adaptee::SpecificRequest" << endl; }
};

// Adapter ( �������� ��������� ������ Adaptee � ������������ � ����������� ������ Target )
class Adapter: public Target {
public:
	Adapter() { m_pAdaptee = new Adaptee; }
	void Request()
	{
		// ��������, ������ ������
		m_pAdaptee->SpecificRequest();
	}

private:
	Adaptee* m_pAdaptee;
};

int main()
{
	Target* target = new Adapter;
	target->Request();

	system("pause");
}