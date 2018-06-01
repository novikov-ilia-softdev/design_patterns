/* Singleton (одиночка)
	 Паттерн гарантирует существование
	 единственного экземпляра класса */

#include <iostream>
#include <conio.h>
using namespace std;

class OnlyOne
{
public:
        //static const OnlyOne& Instance()
		static OnlyOne& Instance()
        {
                static OnlyOne theSingleInstance;
                return theSingleInstance;
        }
		int getValue() { return i; }
		void setValue(int x) { i = x; }
private:        
        OnlyOne(): i(0) {};
        OnlyOne(const OnlyOne& root);
        OnlyOne& operator=(const OnlyOne&);
		int i;
};

int main()
{
	OnlyOne& one = OnlyOne::Instance();
	one.setValue(5);

	OnlyOne& two = OnlyOne::Instance();
	two.setValue(7);

	_getch();
}