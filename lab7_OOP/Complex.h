#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

#if (defined(_MSVC_LANG) ? _MSVC_LANG : __cplusplus) >= 201703L
#define THROW_SPEC(...)
#else
#define THROW_SPEC(...) throw(__VA_ARGS__)
#endif

struct Complex
{
    double re;
    double im;
};

class EmptyComplexException
{
};

class ParamComplexException
{
private:
    std::string message;
    Complex a;
    Complex b;

public:
    ParamComplexException(const std::string& msg, const Complex& a_val, const Complex& b_val);
    const std::string& getMessage() const;
    Complex getA() const;
    Complex getB() const;
};

class InheritedComplexException : public std::domain_error
{
private:
    Complex a;
    Complex b;

public:
    InheritedComplexException(const std::string& message, const Complex& a_val, const Complex& b_val);
    Complex getA() const;
    Complex getB() const;
};

Complex divideNoSpec(const Complex& a, const Complex& b);
Complex divideThrowEmpty(const Complex& a, const Complex& b) throw();
Complex divideStdSpec(const Complex& a, const Complex& b) THROW_SPEC(std::invalid_argument, std::domain_error);
Complex divideCustomEmpty(const Complex& a, const Complex& b) THROW_SPEC(EmptyComplexException);
Complex divideCustomParam(const Complex& a, const Complex& b) THROW_SPEC(ParamComplexException);
Complex divideCustomInherited(const Complex& a, const Complex& b) THROW_SPEC(InheritedComplexException);

void printComplex(const std::string& label, const Complex& c);