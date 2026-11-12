#include <iostream>
#include "Circle.h"
using namespace std;

int main() 
{
    cout << "Testing circle class\n";

    Circle testCircle(2.0, 5.0, 5.0, 0.0, 1.0);
    testCircle.show();
    testCircle.move(5.0, -5.0);
    testCircle.rotate(90.0);
    testCircle.setScale(1.5);
    testCircle.setRadius(8.0);
    testCircle.show();
    testCircle.hide();
    return 0;
}