#include "Circle.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

Circle::Circle(double x, double y, double r, double angle, double scale) : GeometricFigure(x, y, angle, scale) 
{
    radius = (r > 0) ? r : 1.0;
}

void Circle::show() 
{
    isVisible = true;
    double currentRadius = radius * scaleFactor;
    const double PI = 3.141592653589793;

    cout << "\nDisplaying circle on screen\n";
    cout << "Status: visible\n";
    cout << "Center coordinates: (" << centerX << "; " << centerY << ")\n";
    cout << "Base radius: " << radius << "\n";
    cout << "Current radius(scale " << scaleFactor << "x) : " << currentRadius << "\n";
    cout << "Rotation angle: " << rotationAngle << " deg.\n";
    cout << "Circle boundary points coordinates:\n";

    cout << fixed << setprecision(2);

    for (int i = 0; i < 4; ++i) 
    {
        double pointAngleDeg = rotationAngle + i * 90.0;
        double pointAngleRad = pointAngleDeg * PI / 180.0;
        double px = centerX + currentRadius * cos(pointAngleRad);
        double py = centerY + currentRadius * sin(pointAngleRad);
        cout << "Point " << (i + 1) << " (angle " << pointAngleDeg << " deg): (" << px << "; " << py << ")\n";
    }
    cout.unsetf(ios::fixed);
}

void Circle::hide() 
{
    if (isVisible) 
    {
        isVisible = false;
        cout << "\nCircle image at (" << centerX << "; " << centerY << ") destroyed (points removed from screen).\n";
    }
    else 
    {
        cout << "\nCircle is already invisible.\n";
    }
}

void Circle::setRadius(double r) 
{
    if (r > 0) 
    {
        radius = r;
        cout << "New base radius set to: " << radius << "\n";
    }
    else 
    {
        cout << "Radius must be greater than 0!\n";
    }
}

double Circle::getRadius() const 
{
    return radius;
}