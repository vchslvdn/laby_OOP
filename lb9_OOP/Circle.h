#pragma once
#include "GeometricFigure.h"

class Circle : public GeometricFigure 
{
private:
    double radius;

public:
    Circle(double x = 0.0, double y = 0.0, double r = 1.0, double angle = 0.0, double scale = 1.0);

    void show() override;
    void hide() override;

    void setRadius(double r);
    double getRadius() const;
};