#include <iostream>
#include "convtime.h"
#include "Windows.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

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