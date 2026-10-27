#include <cmath>
#include "Complex.h"
using namespace std;


static bool isValid(const Complex& c)
{
    return isfinite(c.re) && isfinite(c.im);
}

static bool isZero(const Complex& c)
{
    return c.re == 0.0 && c.im == 0.0;
}

static Complex rawDivide(const Complex& a, const Complex& b)
{
    double denominator = b.re * b.re + b.im * b.im;

    Complex result;
    result.re = (a.re * b.re + a.im * b.im) / denominator;
    result.im = (a.im * b.re - a.re * b.im) / denominator;
    return result;
}

ParamComplexException::ParamComplexException(const string& msg, const Complex& a_val, const Complex& b_val)
{
    message = msg;
    a = a_val;
    b = b_val;
}

const string& ParamComplexException::getMessage() const
{
    return message;
}

Complex ParamComplexException::getA() const
{
    return a;
}

Complex ParamComplexException::getB() const
{
    return b;
}

InheritedComplexException::InheritedComplexException(const string& message, const Complex& a_val, const Complex& b_val)
    : domain_error(message)
{
    a = a_val;
    b = b_val;
}

Complex InheritedComplexException::getA() const
{
    return a;
}

Complex InheritedComplexException::getB() const
{
    return b;
}

Complex divideNoSpec(const Complex& a, const Complex& b)
{
    if (!isValid(a) || !isValid(b))
    {
        throw invalid_argument("error in divideNoSpec (parameter is NaN or inf)");
    }
    if (isZero(b))
    {
        throw domain_error("error in divideNoSpec (division by zero)");
    }
    return rawDivide(a, b);
}

Complex divideThrowEmpty(const Complex& a, const Complex& b) throw()
{
    if (!isValid(a) || !isValid(b))
    {
        throw invalid_argument("error in divideThrowEmpty (parameter is NaN or inf)");
    }
    if (isZero(b))
    {
        throw domain_error("error in divideThrowEmpty (division by zero)");
    }
    return rawDivide(a, b);
}

Complex divideStdSpec(const Complex& a, const Complex& b) THROW_SPEC(invalid_argument, domain_error)
{
    if (!isValid(a) || !isValid(b))
    {
        throw invalid_argument("error in divideStdSpec (parameter is NaN or inf)");
    }
    if (isZero(b))
    {
        throw domain_error("error in divideStdSpec (division by zero)");
    }
    return rawDivide(a, b);
}

Complex divideCustomEmpty(const Complex& a, const Complex& b) THROW_SPEC(EmptyComplexException)
{
    if (!isValid(a) || !isValid(b) || isZero(b))
    {
        throw EmptyComplexException();
    }
    return rawDivide(a, b);
}

Complex divideCustomParam(const Complex& a, const Complex& b) THROW_SPEC(ParamComplexException)
{
    if (!isValid(a) || !isValid(b))
    {
        throw ParamComplexException("parameter is NaN or inf", a, b);
    }
    if (isZero(b))
    {
        throw ParamComplexException("division by zero", a, b);
    }
    return rawDivide(a, b);
}

Complex divideCustomInherited(const Complex& a, const Complex& b) THROW_SPEC(InheritedComplexException)
{
    if (!isValid(a) || !isValid(b))
    {
        throw InheritedComplexException("error in divideCustomInherited (parameter is NaN or inf)", a, b);
    }
    if (isZero(b))
    {
        throw InheritedComplexException("error in divideCustomInherited (division by zero)", a, b);
    }
    return rawDivide(a, b);
}

void printComplex(const string& label, const Complex& c)
{
    cout << label << ": (" << c.re << ", " << c.im << "i)" << endl;
}