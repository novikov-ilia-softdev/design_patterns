/* Singleton (��������)
	 ������� ����������� �������������
	 ������������� ���������� ������ */

#include <iostream>
#include <conio.h>
using namespace std;

class Singleton {
private:
	static Singleton s;
	int i;
	Singleton(int x): i(x) {}			// ���������
	Singleton& operator = (Singleton&);	// ���������
	Singleton (const Singleton&);		// ���������

public:
	static Singleton& instance() { return s; }
	int getValue() { return i; }
	void setValue(int x) { i = x; }
};

// ���������� ������ Singleton
Singleton Singleton::s(47);

int main()
{
	// �������� 2 ������ �� ������������ ������
	Singleton& s1 = Singleton::instance();	
	cout << "s1.getValue() == " << s1.getValue() << endl;
	Singleton& s2 = Singleton::instance();
	cout << "s2.getValue() == " << s2.getValue() << endl << endl;

	// �������� ������ � ������� 2-�� ������	
	cout << "s2.setValue(9)" << endl << endl;
	s2.setValue(9);
	cout << "s2.getValue() == " << s2.getValue() << endl;

	// � ������� 1-�� ������ ����������, ��� ������ ���������
	cout << "s1.getValue() == " << s1.getValue() << endl;

	_getch();
}