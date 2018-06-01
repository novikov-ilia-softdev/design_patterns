// Паттерн "Composite"

#include <iostream>
#include <list>
#include <algorithm>
#include <memory>
using namespace std;

// Component
class IText{

public:
	typedef shared_ptr<IText> SPtr;

	virtual void draw() = 0;

	virtual void add(const SPtr&) 
	{
		throw std::runtime_error("IText: Can't add to a leaf");
	}

	virtual void remove(const SPtr&)
	{
		throw std::runtime_error("IText: Can't remove from a leaf");
	}
};

// Composite
class CompositeText: public IText{

public:
	void add(const SPtr& sptr)
	{
		children_.push_back(sptr);
	}

	void remove(const SPtr& sptr)
	{
		children_.remove(sptr);
	}

	void replace(const SPtr& oldValue, const SPtr& newValue)
	{
		std::replace(children_.begin(), children_.end(), oldValue, newValue);
	}

	virtual void draw()
	{
		// для каждого shared_ptr в list
		for(SPtr& sptr : children_)
		{
			sptr->draw();
		}
	}

private:
	std::list<SPtr> children_;
};

// Leaf
class Letter: public IText{
public:
	Letter(char c):c_(c) {}

	virtual void draw(){
		std::cout << c_;
	}

private:
	char c_;
};


int main()
{
	CompositeText sentence;

	IText::SPtr lSpace(new Letter(' '));
	IText::SPtr lExcl(new Letter('!'));
	IText::SPtr lComma(new Letter(','));
	IText::SPtr lNewLine(new Letter('\n'));
	IText::SPtr lH(new Letter('H')); // letter 'H'
	IText::SPtr le(new Letter('e')); // letter 'e'
	IText::SPtr ll(new Letter('l')); // letter 'l'
	IText::SPtr lo(new Letter('o')); // letter 'o'
	IText::SPtr lW(new Letter('W')); // letter 'W'
	IText::SPtr lr(new Letter('r')); // letter 'r'
	IText::SPtr ld(new Letter('d')); // letter 'd'
	IText::SPtr li(new Letter('i')); // letter 'i'

	IText::SPtr wHello(new CompositeText);
	wHello->add(lH);
	wHello->add(le);
	wHello->add(ll);
	wHello->add(ll);
	wHello->add(lo);

	IText::SPtr wWorld(new CompositeText); // word "World"
	wWorld->add(lW);
	wWorld->add(lo);
	wWorld->add(lr);
	wWorld->add(ll);
	wWorld->add(ld);

	sentence.add(wHello);
	sentence.add(lComma);
	sentence.add(lSpace);
	sentence.add(wWorld);
	sentence.add(lExcl);
	sentence.add(lNewLine);

	sentence.draw();  // prints "Hello, World!\n"

	IText::SPtr wHi(new CompositeText); // word "Hi"
	wHi->add(lH);
	wHi->add(li);

	sentence.replace(wHello, wHi);
	sentence.draw();  // prints "Hi, World!\n"

	sentence.remove(wWorld);
	sentence.remove(lSpace);
	sentence.remove(lComma);
	sentence.draw();  // prints "Hi!\n"

	system("pause");
}