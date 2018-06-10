#include <iostream>
#include <memory>
#include <string>

class Pizza
{
private:
	std::string dough_;
	std::string sauce_;
	std::string topping_;

public:
	Pizza() {}
	~Pizza() {}
	void setDough(const std::string& d) { dough_ = d; };
	void setSauce(const std::string& s) { sauce_ = s; };
	void setTopping(const std::string& t) { topping_ = t; }
	void showPizza() { std::cout << " Yummy !!!" << std::endl << "Pizza with Dough as " << dough_ << ", Sauce as " << sauce_ << " and Topping as " << topping_ << " !!! " << std::endl;}
};

class IPizzaBuilder
{
protected:
	std::shared_ptr<Pizza> pizza_;
public:
	IPizzaBuilder() {}
	virtual ~IPizzaBuilder() {}
	std::shared_ptr<Pizza> getPizza() { return pizza_; }
	void createNewPizzaProduct() { pizza_.reset (new Pizza); }
	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;

};

class HawaiianPizzaBuilder : public IPizzaBuilder
{
public:
	HawaiianPizzaBuilder() : IPizzaBuilder() {}
	~HawaiianPizzaBuilder(){}
	void buildDough() { pizza_->setDough( "cross"); }
	void buildSauce() { pizza_->setSauce( "mild"); }
	void buildTopping() { pizza_->setTopping( "ham and pineapple"); }
};

class SpicyPizzaBuilder : public IPizzaBuilder
{
public:
	SpicyPizzaBuilder() : IPizzaBuilder() {}
	~SpicyPizzaBuilder() {}
	void buildDough() { pizza_->setDough( "pan baked"); }
	void buildSauce() { pizza_->setSauce( "hot"); }
	void buildTopping() { pizza_->setTopping( "pepperoni and salami"); }
};

class Waiter
{
private:
	IPizzaBuilder* pizzaBuilder_;
public:
	Waiter() : pizzaBuilder_( NULL) {}
	~Waiter() { }

	void setPizzaBuilder( IPizzaBuilder* b) { pizzaBuilder_ = b; }
	std::shared_ptr<Pizza> getPizza() { return pizzaBuilder_->getPizza(); }
	void constructPizza()
	{
		pizzaBuilder_->createNewPizzaProduct();
		pizzaBuilder_->buildDough();
		pizzaBuilder_->buildSauce();
		pizzaBuilder_->buildTopping();
	}
};

int main()
{ 
	Waiter waiter;

	HawaiianPizzaBuilder hawaiianPizzaBuilder;
	waiter.setPizzaBuilder (&hawaiianPizzaBuilder);
	waiter.constructPizza();
	std::shared_ptr<Pizza> pizza_ = waiter.getPizza();
	pizza_->showPizza();

	SpicyPizzaBuilder spicyPizzaBuilder;
	waiter.setPizzaBuilder(&spicyPizzaBuilder);
	waiter.constructPizza();
	pizza_ = waiter.getPizza();
	pizza_->showPizza();
}
