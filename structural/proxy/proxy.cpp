#include <iostream>
#include <memory>

class IMath 
{
public:
    virtual double add(double, double) = 0;
    virtual double sub(double, double) = 0;
    virtual double mul(double, double) = 0;
    virtual double div(double, double) = 0;
	virtual ~IMath() {}
};

class Math : public IMath 
{
public:
    double add( double x, double y) { return x + y; }
    double sub( double x, double y) { return x - y; }
    double mul( double x, double y) { return x * y; }
    double div( double x, double y) { return x / y; }
};

class MathProxy : public IMath 
{
public:
    MathProxy() { math = new Math(); }
    ~MathProxy() { delete math; }

    double add( double x, double y) { return math->add(x, y); }
    double sub( double x, double y) { return math->sub(x, y); }
    double mul( double x, double y) { return math->mul(x, y); }
    double div( double x, double y) { return math->div(x, y); }

private:
    IMath *math;
};

int main()
{
	std::shared_ptr<IMath> proxy( new MathProxy());
	std::cout << "4 + 2 = " << proxy->add(4, 2) << std::endl;
	std::cout << "4 - 2 = " << proxy->sub(4, 2) << std::endl;
	std::cout << "4 * 2 = " << proxy->mul(4, 2) << std::endl;
	std::cout << "4 / 2 = " << proxy->div(4, 2) << std::endl;
}
