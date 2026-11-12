#pragma once

class GeometricFigure 
{
protected:
    double centerX;
    double centerY;
    double rotationAngle;
    double scaleFactor;
    bool isVisible;

public:
    GeometricFigure(double x = 0.0, double y = 0.0, double angle = 0.0, double scale = 1.0);
    virtual ~GeometricFigure();

    virtual void show() = 0;
    virtual void hide() = 0;

    virtual void rotate(double deltaAngle);
    virtual void move(double dx, double dy);

    void setScale(double newScale);
    double getCenterX() const;
    double getCenterY() const;
    double getRotationAngle() const;
    double getScaleFactor() const;
    bool getVisibility() const;
};