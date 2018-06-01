// ������� "Memento"

#include <iostream>
#include <string>
using namespace std;

class Memento;

// Originator
class Originator {
public:
	string GetState() const { return _state; }
	void SetState( const string& str ) 
	{
		_state = str;
		ShowState();
	}

	void ShowState() const { cout << "State = " << _state << endl; }
	
	Memento* CreateMemento();
	void SetMemento( const Memento& memento );

private:
	string _state;
};

// Memento
class Memento {
public:
	Memento() {}

private:
	friend class Originator;
	
	Memento( const string& state ) { this->_state = state; }
	string GetState() const { return _state; }

private:
	string _state;
};

// Caretaker
class Caretaker {
public:
	Caretaker() {}
	Memento GetMemento() const { return _memento; }
	void SetMemento( const Memento& memento ) { _memento = memento; }

private:
	Memento _memento;
};

// ���������� Originator
Memento* Originator::CreateMemento() 
{
	return ( new Memento(_state) );
}

void Originator::SetMemento( const Memento& memento )
{
	cout << "Restoring state..." << endl;
	_state = memento.GetState();
}

int main()
{
	// ������
	Originator o;
	o.SetState("On");

	// ��������� ���������� ���������
	Caretaker c;
	c.SetMemento( *( o.CreateMemento() ) );

	// �������� ���������
	o.SetState( "Off" );

	// ��������������� �������� ���������
	o.SetMemento( c.GetMemento() );

	// ���������� ��������� ��������������
	o.ShowState();

	cout << endl;
	system("pause");
	return 0; 
}