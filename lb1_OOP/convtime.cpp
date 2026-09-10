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
    cout << "Input hours: " << endl;
    cin >> this->first;

    cout << "Input minutes: " << endl;
    cin >> this->second;
}

void convtime::Display()
{
    cout << "Time: " << first << " hours " << second << " minutes" << endl;
}

int convtime::minutes()
{
    int total_minutes = (first * 60) + second;
    cout << "Total time in minutes: " << total_minutes << " min" << endl;
    return total_minutes;
}