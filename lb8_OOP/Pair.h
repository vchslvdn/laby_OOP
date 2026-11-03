#pragma once
#include <iostream>

class Pair 
{
protected:
    double first;
    double second;

public:
    Pair(double a = 1.0, double b = 1.0);
    Pair(const Pair& other);
    virtual ~Pair();

    void setFirst(double a);
    void setSecond(double b);
    void setPair(double a, double b);

    double getFirst() const;
    double getSecond() const;

    double getProduct() const;

    virtual void print() const;
};

Pair processPair(Pair p, double scale);
void inspectObject(const Pair& obj);