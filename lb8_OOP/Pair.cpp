#include "Pair.h"
using namespace std;

Pair::Pair(double a, double b) : first(a), second(b) 
{
}

Pair::Pair(const Pair& other) : first(other.first), second(other.second) 
{
}

Pair::~Pair() 
{
}

void Pair::setFirst(double a) 
{ 
    first = a;
}

void Pair::setSecond(double b)
{
    second = b; 
}

void Pair::setPair(double a, double b) 
{
    first = a;
    second = b;
}

double Pair::getFirst() const
{
    return first; 
}

double Pair::getSecond() const
{
    return second; 
}

double Pair::getProduct() const 
{
    return first * second;
}

void Pair::print() const 
{
    cout << "Pair(" << first << ", " << second << ")" << endl;
    cout << "Product: " << getProduct() << endl;
}

Pair processPair(Pair p, double scale) 
{
    p.setFirst(p.getFirst() * scale);
    p.setSecond(p.getSecond() * scale);
    return p;
}

void inspectObject(const Pair& obj) 
{
    obj.print();
}