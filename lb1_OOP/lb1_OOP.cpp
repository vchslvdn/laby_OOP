#include <iostream>
#include "convtime.h"
using namespace std;

int main()
{
    convtime A;
    A.init(2, 30);
    A.Display();
    A.minutes();
    cout << endl;

    convtime B;
    B.Read();
    B.Display();
    B.minutes();

    return 0;
}