#include <iostream>
#include "convtime.h"

using namespace std;

void convtime::init(int f, int s)
{
    this->first = f;
    this->second = s;
}

void convtime::Read()
{
    cout << "Введіть години: " << endl;
    cin >> this->first;

    cout << "Введіть хвилини: " << endl;
    cin >> this->second;
}

void convtime::Display()
{
    cout << "Час: " << first << " год " << second << " хв" << endl;
}

int convtime::minutes()
{
    int total_minutes = (first * 60) + second;
    cout << "Загальний час у хвилинах: " << total_minutes << " хв" << endl;
    return total_minutes;
}