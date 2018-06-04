#include <iostream>
#include <list>
#include <algorithm>
#include <memory>

class IText{
public:
	typedef std::shared_ptr<IText> ITextPtr;
	virtual void draw() = 0;
	virtual void add(const ITextPtr&) { throw std::runtime_error( "IText: Can't add to a leaf");}
	virtual void remove(const ITextPtr&) {throw std::runtime_error( "IText: Can't remove from a leaf");}
	virtual void replace( const ITextPtr& oldValue, const ITextPtr& newValue) {throw std::runtime_error( "IText: Can't replace from a leaf");}
};

class CompositeText: public IText{
public:
	void add(const ITextPtr& textPtr){ children_.push_back(textPtr); }
	void remove(const ITextPtr& textPtr) { children_.remove(textPtr);}
	void replace( const ITextPtr& oldValue, const ITextPtr& newValue)
	{
		std::replace( children_.begin(), children_.end(), oldValue, newValue);
	}
	virtual void draw() { for( ITextPtr& sptr : children_) { sptr->draw(); } }
private:
	std::list<ITextPtr> children_;
};

class Letter: public IText{
public:
	Letter( char c): c_(c) {}
	virtual void draw(){ std::cout << c_; }
private:
	char c_;
};

int main()
{
	IText::ITextPtr sentence( new CompositeText);

	IText::ITextPtr lSpace( new Letter(' '));
	IText::ITextPtr lExcl( new Letter('!'));
	IText::ITextPtr lComma( new Letter(','));
	IText::ITextPtr lNewLine( new Letter('\n'));
	IText::ITextPtr lH( new Letter('H'));
	IText::ITextPtr le( new Letter('e'));
	IText::ITextPtr ll( new Letter('l'));
	IText::ITextPtr lo( new Letter('o'));
	IText::ITextPtr lW( new Letter('W'));
	IText::ITextPtr lr( new Letter('r'));
	IText::ITextPtr ld( new Letter('d'));
	IText::ITextPtr li( new Letter('i'));

	IText::ITextPtr wHello( new CompositeText);
	wHello->add(lH);
	wHello->add(le);
	wHello->add(ll);
	wHello->add(ll);
	wHello->add(lo);

	IText::ITextPtr wWorld( new CompositeText);
	wWorld->add(lW);
	wWorld->add(lo);
	wWorld->add(lr);
	wWorld->add(ll);
	wWorld->add(ld);

	sentence->add( wHello);
	sentence->add( lComma);
	sentence->add( lSpace);
	sentence->add( wWorld);
	sentence->add( lExcl);
	sentence->add( lNewLine);

	sentence->draw();	// Hello, World!

	IText::ITextPtr wHi( new CompositeText);
	wHi->add( lH);
	wHi->add( li);

	sentence->replace( wHello, wHi);
	sentence->draw();	// Hi, World!

	sentence->remove( wWorld);
	sentence->remove( lSpace);
	sentence->remove( lComma);
	sentence->draw();	// Hi!
}
