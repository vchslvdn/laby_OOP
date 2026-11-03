#include <iostream>
#include "Pair.h"
#include "Rightangled.h"

using namespace std;

int main() 
{
    cout << "Testing base class Pair\n";
    Pair basePair(2.5, 4.0);
    basePair.print();

    basePair.setFirst(5.0);
    basePair.setSecond(6.0);
    cout << "After modifying fields: ";
    basePair.print();

    cout << "\nTesting derived class Rightangled\n";
    Rightangled triangle(3.0, 4.0);
    triangle.print();

    triangle.setPair(6.0, 8.0);
    cout << "After changing legs to 6 and 8: ";
    triangle.print();

    cout << "\nSubstitution principle demonstration\n";

    cout << "\nA) Passing base class Pair to processPair (multiply by 2):\n";
    Pair resultFromPair = processPair(basePair, 2.0);
    cout << "Result: ";
    resultFromPair.print();

    cout << "\nB) Passing derived class Rightangled to processPair (multiply by 0.5):\n";
    Pair resultFromTriangle = processPair(triangle, 0.5);
    cout << "Result as Pair: ";
    resultFromTriangle.print();

    Rightangled scaledTriangle(resultFromTriangle);
    cout << "Converted back to Rightangled: ";
    scaledTriangle.print();

    cout << "\nC) Polymorphic substitution via base reference:\n";
    cout << "Base object: ";
    inspectObject(basePair);
    cout << "Derived object: ";
    inspectObject(triangle);

    return 0;
}