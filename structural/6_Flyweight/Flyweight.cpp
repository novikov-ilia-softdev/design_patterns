// Паттерн "Flyweight"

#include <map>
#include <iostream>

// "Flyweight"
class Character{
public: 
	virtual void display() const = 0;

protected: 
	char mSymbol;
	int  mWidth;
	int  mHeight;
	int  mAscent;
	int  mDescent;
	int  mPointSize;
};

// "ConcreteFlyweight"
class ConcreteCharacter : public Character{
public: 
	// Constructor
	ConcreteCharacter( char aSymbol, int aPointSize )
	{
		mSymbol         = aSymbol;
		mHeight         = 100;
		mWidth          = 120;
		mAscent         = 70;
		mDescent        = 0;
		mPointSize      = aPointSize;
	}

	// from Character
	virtual void display() const
	{
		std::cout << mSymbol << " ( PointSize " << mPointSize << " )\n";
	}
};

// "FlyweightFactory"
template< int POINT_SIZE = 10 >
class CharacterFactory{

public: 
	const Character& getCharacter( char aKey )
	{
		// Uses "lazy initialization"
		Characters::const_iterator it = mCharacters.find( aKey );
		// если такого еще нет - создаем
		if ( mCharacters.end() == it )
		{
			const Character* character = new ConcreteCharacter(aKey, POINT_SIZE);
			mCharacters[aKey] = character;
			return *character;
		}
		else
		{
			return *it->second;
		}
	}

	virtual ~CharacterFactory()
	{
		for (Characters::const_iterator it = mCharacters.begin(); it != mCharacters.end(); it++)
			delete it->second;
	}

private: 
	typedef std::map< char, const Character* > Characters;   
	Characters mCharacters;
};

int main()
{
	std::string document = "AAZZBBZB";

	CharacterFactory<12> characterFactory;

	for (std::string::const_iterator it = document.begin(); it != document.end(); it++)
	{
		const Character& character = characterFactory.getCharacter( *it );
		character.display();
	}

	system("pause");
}