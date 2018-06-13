#include <iostream>

class Stack{
public:
    friend class StackIter;
    Stack() { sp_ = -1;}
    void push(int in) { items_[++sp_] = in;}
    int pop() { return items_[sp_--]; }
    bool isEmpty() { return( sp_ == -1); }
private:
    int items_[10];
    int sp_;
};

class StackIter{
public:
    StackIter(const Stack &s): stk_(s) { index_ = 0; }
    void operator++() { index_++; }
    bool operator()() { return index_ != stk_.sp_ + 1; }
    int operator *() {return stk_.items_[index_];}
private:
    const Stack &stk_;
    int index_;
};

bool operator == (const Stack &l, const Stack &r)
{
	StackIter itl(l), itr(r);
	for (; itl(); ++itl, ++itr)
		if (*itl != *itr)
			break;

	return !itl() && !itr();
}

int main()
{
	Stack s1;
	int i;
	for (i = 1; i < 5; i++)
		s1.push(i);

	Stack s2(s1), s3(s1), s4(s1), s5(s1);
	s3.pop();
	s5.pop();
	s4.push(2);
	s5.push(9);
	std::cout << "1 == 2 is " << (s1 == s2) << std::endl;
	std::cout << "1 == 3 is " << (s1 == s3) << std::endl;
	std::cout << "1 == 4 is " << (s1 == s4) << std::endl;
	std::cout << "1 == 5 is " << (s1 == s5) << std::endl;
}
