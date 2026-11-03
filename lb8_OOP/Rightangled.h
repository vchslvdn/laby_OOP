#pragma once
#include "Pair.h"

class Rightangled : public Pair 
{
public:
    Rightangled(double a = 3.0, double b = 4.0);
    Rightangled(const Pair& p);

    double getHypotenuse() const;
    double getArea() const;

    void print() const override;
};