#include <map>
#include <iostream>

class ICharacter{
public: 
	virtual void display() const = 0;

protected: 
	char symbol_;
	int  width_;
	int  height_;
	int  ascent_;
	int  descent_;
	int  pointSize_;
};

class ConcreteCharacter : public ICharacter{
public: 
	ConcreteCharacter( char symbol, int pointSize )
	{
		symbol_ = symbol;
		height_ = 100;
		width_ = 120;
		ascent_ = 70;
		descent_ = 0;
		pointSize_ = pointSize;
	}
	virtual void display() const { std::cout << "symbol: " << symbol_ << " ( pointSize: " << pointSize_ << " )" << std::endl; }
};

template< int POINT_SIZE = 10 >
class CharacterFactory{
public: 
	const ICharacter& getCharacter( char aKey )
	{
		Characters::const_iterator it = characters_.find( aKey );
		if ( characters_.end() == it )
		{
			const ICharacter* character = new ConcreteCharacter( aKey, POINT_SIZE);
			characters_[aKey] = character;
			return *character;
		}
		else
		{
			return *it->second;
		}
	}

	virtual ~CharacterFactory()
	{
		for (Characters::const_iterator it = characters_.begin(); it != characters_.end(); it++)
			delete it->second;
	}

private: 
	typedef std::map< char, const ICharacter* > Characters;
	Characters characters_;
};

int main()
{
	std::string document = "AAZZBBZB";
	CharacterFactory<12> characterFactory;

	for( std::string::const_iterator it = document.begin(); it != document.end(); it++)
	{
		const ICharacter& character = characterFactory.getCharacter( *it );
		character.display();
	}
}
