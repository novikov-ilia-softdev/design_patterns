/* Singleton (одиночка)
	 Паттерн гарантирует существование
	 единственного экземпляра класса */

#include <iostream>
#include <conio.h>
using namespace std;

class Singleton {
private:
	static Singleton s;
	int i;
	Singleton(int x): i(x) {}			// Запрещено
	Singleton& operator = (Singleton&);	// Запрещено
	Singleton (const Singleton&);		// Запрещено

public:
	static Singleton& instance() { return s; }
	int getValue() { return i; }
	void setValue(int x) { i = x; }
};

// Определяем объект Singleton
Singleton Singleton::s(47);

int main()
{
	// Получаем 2 ссылки на единственный объект
	Singleton& s1 = Singleton::instance();	
	cout << "s1.getValue() == " << s1.getValue() << endl;
	Singleton& s2 = Singleton::instance();
	cout << "s2.getValue() == " << s2.getValue() << endl << endl;

	// Изменяем объект с помощью 2-ой ссылки	
	cout << "s2.setValue(9)" << endl << endl;
	s2.setValue(9);
	cout << "s2.getValue() == " << s2.getValue() << endl;

	// С помощью 1-ой ссылки показываем, что объект изменился
	cout << "s1.getValue() == " << s1.getValue() << endl;

	_getch();
}