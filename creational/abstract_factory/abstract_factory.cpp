
#include <iostream>

class ICar
{
public:
	virtual void printName() = 0;
	virtual ~ICar(){}
};

class Ford : public ICar
{
public:
	virtual void printName() { std::cout << "Ford" << std::endl; }
};

class Toyota : public ICar
{
public:
	virtual void printName() { std::cout << "Toyota" << std::endl; }
};

class IEngine
{
public:
	virtual void printPower() = 0;
	virtual ~IEngine(){}
};

class FordEngine : public IEngine
{
public:
	virtual void printPower() { std::cout << "Ford Engine 4.4" << std::endl; }
};

class ToyotaEngine : public IEngine
{
public:
	virtual void printPower() { std::cout << "Toyota Engine 3.2" << std::endl; }
};


class ICarFactory
{
public:
	virtual ICar* createCar()    = 0;
	virtual IEngine* createEngine() = 0;
};

class FordFactory : public ICarFactory
{
public:
	virtual ICar* createCar(){ return new Ford();}
	virtual IEngine* createEngine(){ return new FordEngine();}
};

class ToyotaFactory : public ICarFactory
{
public:
	virtual ICar* createCar(){ return new Toyota();}
	virtual IEngine* createEngine(){ return new ToyotaEngine();}
};


void use( ICarFactory* f)
{
	ICar* myCar = f->createCar();
	IEngine* myEngine = f->createEngine();

	myCar->printName();
	myEngine->printPower();

	delete myCar;
	delete myEngine;
}


int main()
{
	ToyotaFactory toyotaFactory;
	FordFactory fordFactory;

	use (&toyotaFactory);
	use (&fordFactory);
}
