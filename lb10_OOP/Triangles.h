#pragma once

struct Point 
{
    double x, y;
};

struct MedianBases 
{
};

class Triangle
{
public:
    virtual ~Triangle() = default;

    virtual double getSideA() const = 0;
    virtual double getSideB() const = 0;
    virtual double getSideC() const = 0;

    double getSide(int index) const;
    double getMedian(int sideIndex) const;
    double getMidline(int sideIndex) const;
    double getSemiPerimeter() const;

    virtual double getArea() const;
    virtual double getInradius() const;
    virtual double getCircumradius() const;

    virtual void printInfo() const = 0;

protected:
    static bool isValidTriangle(double a, double b, double c);
    static double distance(const Point& p1, const Point& p2);
};

class VertexTriangle : public Triangle 
{
private:
    Point A, B, C;

    static Point restoreVertex(const Point& ownBase, const Point& base1, const Point& base2);

public:
    VertexTriangle(Point p1, Point p2, Point p3);
    VertexTriangle(Point m1, Point m2, Point m3, MedianBases);

    double getSideA() const override;
    double getSideB() const override;
    double getSideC() const override;

    void printInfo() const override;
};

class SideTriangle : public Triangle 
{
protected:
    double a, b, c;

public:
    SideTriangle(double sideA, double sideB, double sideC);
    SideTriangle(Point m1, Point m2, Point m3, MedianBases);

    static SideTriangle fromMedianLengths(double ma, double mb, double mc);

    double getSideA() const override;
    double getSideB() const override;
    double getSideC() const override;

    void printInfo() const override;
};

class RightTriangle : public SideTriangle
{
public:
    RightTriangle(double legA, double legB);
    RightTriangle(double legA, double legB, double hypotenuseC);

    double getArea() const override;
    double getInradius() const override;
    double getCircumradius() const override;

    void printInfo() const override;
};