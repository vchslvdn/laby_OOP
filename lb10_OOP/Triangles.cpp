#include "Triangles.h"
#include <cmath>
#include <iostream>
using namespace std;

double Triangle::getSide(int index) const 
{
    switch (index) 
    {
    case 1: 
        return getSideA();
    case 2: 
        return getSideB();
    case 3: 
        return getSideC();
    default: 
        throw invalid_argument("Side index must be 1, 2 or 3.");
    }
}

double Triangle::getMedian(int sideIndex) const 
{
    double a = getSideA();
    double b = getSideB();
    double c = getSideC();

    switch (sideIndex) 
    {
    case 1:
        return 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
    case 2: 
        return 0.5 * sqrt(2 * a * a + 2 * c * c - b * b);
    case 3: 
        return 0.5 * sqrt(2 * a * a + 2 * b * b - c * c);
    default:
        throw invalid_argument("Side index must be 1, 2 or 3.");
    }
}

double Triangle::getMidline(int sideIndex) const 
{
    return getSide(sideIndex) / 2.0;
}

double Triangle::getSemiPerimeter() const 
{
    return (getSideA() + getSideB() + getSideC()) / 2.0;
}

double Triangle::getArea() const 
{
    double p = getSemiPerimeter();
    return sqrt(p * (p - getSideA()) * (p - getSideB()) * (p - getSideC()));
}

double Triangle::getInradius() const 
{
    return getArea() / getSemiPerimeter();
}

double Triangle::getCircumradius() const 
{
    return (getSideA() * getSideB() * getSideC()) / (4.0 * getArea());
}

bool Triangle::isValidTriangle(double a, double b, double c) 
{
    if (!(a > 0 && b > 0 && c > 0)) 
    {
        return false;
    }
    const double eps = 1e-9 * max({ a, b, c });
    return (a + b > c + eps) && (a + c > b + eps) && (b + c > a + eps);
}

double Triangle::distance(const Point& p1, const Point& p2) 
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

Point VertexTriangle::restoreVertex(const Point& ownBase, const Point& base1, const Point& base2) 
{
    return 
    { 
        base1.x + base2.x - ownBase.x, base1.y + base2.y - ownBase.y 
    };
}

VertexTriangle::VertexTriangle(Point p1, Point p2, Point p3) : A(p1), B(p2), C(p3) 
{
    if (!isValidTriangle(getSideA(), getSideB(), getSideC())) 
    {
        throw invalid_argument("Points are collinear (degenerate triangle).");
    }
}

VertexTriangle::VertexTriangle(Point m1, Point m2, Point m3, MedianBases) : VertexTriangle(restoreVertex(m1, m2, m3),
        restoreVertex(m2, m1, m3),
        restoreVertex(m3, m1, m2)) 
{
}

double VertexTriangle::getSideA() const 
{
    return distance(B, C); 
}
double VertexTriangle::getSideB() const 
{ 
    return distance(A, C);
}
double VertexTriangle::getSideC() const 
{ 
    return distance(A, B);
}

void VertexTriangle::printInfo() const 
{
    cout << "Vertex triangle: " << "A(" << A.x << ", " << A.y << "), " << "B(" << B.x << ", " << B.y << "), " << "C(" << C.x << ", " << C.y << ")\n";
    cout << "Sides: a = " << getSideA() << ", b = " << getSideB() << ", c = " << getSideC() << "\n";
}

SideTriangle::SideTriangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) 
{
    if (a <= 0 || b <= 0 || c <= 0) 
    {
        throw invalid_argument("Side lengths must be positive.");
    }
    if (!isValidTriangle(a, b, c)) 
    {
        throw invalid_argument("Triangle inequality violated for the given sides.");
    }
}

SideTriangle::SideTriangle(Point m1, Point m2, Point m3, MedianBases) : SideTriangle(2.0 * distance(m2, m3), 2.0 * distance(m1, m3),  2.0 * distance(m1, m2)) 
{
}

SideTriangle SideTriangle::fromMedianLengths(double ma, double mb, double mc) 
{
    if (!isValidTriangle(ma, mb, mc)) 
    {
        throw invalid_argument("Cannot form a triangle from the given medians.");
    }
    double sideA = (2.0 / 3.0) * sqrt(2 * mb * mb + 2 * mc * mc - ma * ma);
    double sideB = (2.0 / 3.0) * sqrt(2 * ma * ma + 2 * mc * mc - mb * mb);
    double sideC = (2.0 / 3.0) * sqrt(2 * ma * ma + 2 * mb * mb - mc * mc);
    return SideTriangle(sideA, sideB, sideC);
}

double SideTriangle::getSideA() const 
{ 
    return a;
}
double SideTriangle::getSideB() const
{
    return b;
}
double SideTriangle::getSideC() const
{
    return c; 
}

void SideTriangle::printInfo() const 
{
    cout << "Side triangle: " << "a = " << a << ", b = " << b << ", c = " << c << "\n";
}

RightTriangle::RightTriangle(double legA, double legB)
    : SideTriangle(legA, legB, hypot(legA, legB))
{
}

RightTriangle::RightTriangle(double legA, double legB, double hypotenuseC) : SideTriangle(legA, legB, hypotenuseC) 
{
    if (fabs(a * a + b * b - c * c) > 1e-9 * c * c) 
    {
        throw invalid_argument("Not a right triangle (Pythagorean theorem failed).");
    }
}

double RightTriangle::getArea() const 
{
    return 0.5 * a * b;
}

double RightTriangle::getInradius() const
{
    return (a + b - c) / 2.0;
}

double RightTriangle::getCircumradius() const 
{
    return c / 2.0;
}

void RightTriangle::printInfo() const 
{
    cout << "Right triangle: legs a = " << a << ", b = " << b << ", hypotenuse c = " << c << "\n";
}