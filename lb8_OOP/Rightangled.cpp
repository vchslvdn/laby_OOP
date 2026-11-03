#include "Rightangled.h"
#include <cmath>
using namespace std;

Rightangled::Rightangled(double a, double b) : Pair(a, b) 
{
    if (a <= 0 || b <= 0) 
    {
        cout << "Warning: legs must be positive! Set to 1.0 and 1.0.\n";
        first = 1.0;
        second = 1.0;
    }
}

Rightangled::Rightangled(const Pair& p) : Pair(p) 
{
    if (first <= 0 || second <= 0) 
    {
        first = abs(first) > 0 ? abs(first) : 1.0;
        second = abs(second) > 0 ? abs(second) : 1.0;
    }
}

double Rightangled::getHypotenuse() const 
{
    return hypot(first, second);
}

double Rightangled::getArea() const 
{
    return getProduct() / 2.0;
}

void Rightangled::print() const 
{
    cout << "rightangled(legs: " << first << ", " << second << ")" << endl;
    cout << "hypotenuse: " << getHypotenuse() << endl;
    cout << "area: " << getArea() << endl;
}