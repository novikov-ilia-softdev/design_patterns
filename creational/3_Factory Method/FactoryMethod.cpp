// Паттерн "Фабричный метод"

# include<iostream>
# include<string>
using namespace std;

// Product
class Product {
public:
	virtual string getName() = 0;
	virtual ~Product() {}
};

// ConcreteProductA
class ConcreteProductA : public Product {
public:
	string getName() {
		return "ConcreteProductA";
	}
};

// ConcreteProductB
class ConcreteProductB : public Product {
public:
	string getName() {
		return "ConcreteProductB";
	}
};

// Creator
class Creator {
public: 
	virtual Product* factoryMethod() = 0;
};

// ConcreteCreatorA
class ConcreteCreatorA : public Creator {
public:
	Product* factoryMethod() {
		return new ConcreteProductA();
	}
};

// ConcreteCreatorB
class ConcreteCreatorB : public Creator {
public: 
	Product* factoryMethod() {
		return new ConcreteProductB();
	}
};

int main() {
	const size_t count = 2;
	// An array of creators
	Creator* creators[count] = { new ConcreteCreatorA(), new ConcreteCreatorB() };


	// Iterate over creators and create products
	for (size_t i = 0; i < count; i++) {
		Product* product = creators[i]->factoryMethod();
		cout << product->getName() << endl;
		delete product;
	}

	for (size_t i = 0; i < count; i++)
		delete creators[i];

	system("pause");
	return 0;
}