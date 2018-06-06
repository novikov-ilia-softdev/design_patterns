#include <iostream>
#include <string>

class IProduct {
public:
	virtual std::string getName() = 0;
	virtual ~IProduct() {}
};

class ConcreteProductA : public IProduct {
public:
	std::string getName() { return "ConcreteProductA";}
};

class ConcreteProductB : public IProduct {
public:
	std::string getName() { return "ConcreteProductB";}
};

class ICreator {
public: 
	virtual IProduct* factoryMethod() = 0;
};

class ConcreteCreatorA : public ICreator {
public:
	IProduct* factoryMethod() { return new ConcreteProductA(); }
};

class ConcreteCreatorB : public ICreator {
public: 
	IProduct* factoryMethod() { return new ConcreteProductB(); }
};

int main() {
	const size_t count = 2;
	ICreator* creators[count] = { new ConcreteCreatorA(), new ConcreteCreatorB() };

	for (size_t i = 0; i < count; i++) {
		IProduct* product = creators[i]->factoryMethod();
		std::cout << product->getName() << std::endl;
		delete product;
	}

	for (size_t i = 0; i < count; i++)
		delete creators[i];
}
