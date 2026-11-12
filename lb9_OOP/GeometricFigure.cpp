#include "GeometricFigure.h"
#include <iostream>
#include <cmath>
using namespace std;

GeometricFigure::GeometricFigure(double x, double y, double angle, double scale) : centerX(x), centerY(y), rotationAngle(angle), scaleFactor(scale), isVisible(false)
{
    if (scaleFactor <= 0) 
    {
        scaleFactor = 1.0;
    }
}

GeometricFigure::~GeometricFigure() 
{
}

void GeometricFigure::rotate(double deltaAngle) 
{
    rotationAngle = fmod(rotationAngle + deltaAngle, 360.0);
    if (rotationAngle < 0) 
    {
        rotationAngle += 360.0;
    }
    cout << "Figure rotated by " << deltaAngle << " deg. Current angle: " << rotationAngle << " deg.\n";
}

void GeometricFigure::move(double dx, double dy) 
{
    centerX += dx;
    centerY += dy;
    cout << "Vector (" << dx << "; " << dy << "). New center: (" << centerX << "; " << centerY << ")\n";
}

void GeometricFigure::setScale(double newScale) 
{
    if (newScale > 0) 
    {
        scaleFactor = newScale;
        cout << "Scale factor set to: " << scaleFactor << "x\n";
    }
    else 
    {
        cout << "Error! Scale factor must be positive!\n";
    }
}

double GeometricFigure::getCenterX() const 
{ 
    return centerX;
}
double GeometricFigure::getCenterY() const 
{ 
    return centerY; 
}
double GeometricFigure::getRotationAngle() const 
{
    return rotationAngle; 
}
double GeometricFigure::getScaleFactor() const 
{ 
    return scaleFactor; 
}
bool GeometricFigure::getVisibility() const 
{ 
    return isVisible; 
}