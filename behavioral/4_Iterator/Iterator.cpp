// Паттерн "Iterator"

#include <iostream>
#include <list>
using namespace std;

// Абстрактный итератор
class Iterator {
public:
	virtual void First()				= 0;
	virtual void Next()					= 0;
	virtual bool IsDone() const			= 0;
	virtual int CurrentItem() const		= 0; 
};

// Абстрактный лист
class AbstractList {
public:
	virtual Iterator* CreateIterator()			= 0;
	virtual int Count()	const					= 0;
	virtual void Append(const int& item)		= 0;
	virtual void Remove(const int& item)		= 0;
	virtual int Get(int index)					= 0;
};

class ListIterator;

// Конкретный лист
class ConcreteList: public AbstractList {
public:
	virtual Iterator* CreateIterator();

	virtual int Count() const { return _list.size(); }

	virtual void Append(const int& item) { _list.push_back(item); }

	virtual void Remove(const int& item) { _list.remove(item); }

	virtual int Get(int index)
	{
		// обойти лист итератором (встроенным)
		int count = 0;
		for( list<int>::iterator it = _list.begin(); it != _list.end(); it++, count++ )
		{
			if ( count == index )
			{
				return *it;
			}
		}
		return -1;
	}

private:
	list<int> _list;
};

// Конкретный итератор
class ListIterator: public Iterator {
public:
	ListIterator( ConcreteList* aList ):
		_list(aList), _current(0) {}

	virtual void First() { _current = 0; }

	virtual void Next() { _current++; }

	virtual bool IsDone() const { return _current >= _list->Count(); }

	virtual int CurrentItem() const
	{
		if ( !IsDone() )
		{
			return _list->Get(_current);
		}
		return -1;
	}

private:
	ConcreteList* _list;
	int _current;
};

Iterator* ConcreteList::CreateIterator()
{
	return new ListIterator( this );
}


int main( int argc, char* argv[] )
{
	AbstractList* pList = new ConcreteList;

	for ( int i=0; i<7; ++i )
	{
		pList->Append( i );
	}

	Iterator* iter = pList->CreateIterator();

	cout << "List:" << endl;
	iter->First();
	
	while( !iter->IsDone() )
	{
		cout << iter->CurrentItem() << endl;
		iter->Next();
	}
	
	cout << endl;
	system("pause");
	return 0; 
}