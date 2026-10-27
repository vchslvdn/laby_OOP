#include <iostream>
#include <exception>
#include <cstdlib>
#include <limits>
#include "Complex.h"

using namespace std;

void myTerminate()
{
    cout << "terminate(): function with throw() specification tried to throw an exception" << endl;
    exit(1);
}

int main()
{
    Complex a = { 4.0, 2.0 };
    Complex b_valid = { 1.0, -1.0 };
    Complex b_zero = { 0.0, 0.0 };
    Complex a_nan = { numeric_limits<double>::quiet_NaN(), 1.0 };

    cout << "Valid division test" << endl;
    try
    {
        Complex res = divideNoSpec(a, b_valid);
        printComplex("Result of A / B_valid", res);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    
    cout << "\nFunction without exception specification" << endl;
    try
    {
        Complex res = divideNoSpec(a, b_zero);
        printComplex("Result", res);
    }
    catch (const domain_error& e)
    {
        cout << "Caught domain error: " << e.what() << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught invalid argument: " << e.what() << endl;
    }

    try
    {
        Complex res = divideNoSpec(a_nan, b_valid);
        printComplex("Result", res);
    }
    catch (const domain_error& e)
    {
        cout << "Caught domain error: " << e.what() << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught invalid argument: " << e.what() << endl;
    }

    cout << "\nFunction with standard exception specification" << endl;
    try
    {
        Complex res = divideStdSpec(a, b_zero);
        printComplex("Result", res);
    }
    catch (const domain_error& e)
    {
        cout << "Caught domain error: " << e.what() << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught invalid argument: " << e.what() << endl;
    }

    try
    {
        Complex res = divideStdSpec(a_nan, b_valid);
        printComplex("Result", res);
    }
    catch (const domain_error& e)
    {
        cout << "Caught domain error: " << e.what() << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught invalid argument: " << e.what() << endl;
    }

    cout << "\nCustom exception: empty class" << endl;
    try
    {
        Complex res = divideCustomEmpty(a, b_zero);
        printComplex("Result", res);
    }
    catch (const EmptyComplexException&)
    {
        cout << "Caught EmptyComplexException: error occurred (no details available)" << endl;
    }

    cout << "\nCustom exception: independent class with parameters" << endl;
    try
    {
        Complex res = divideCustomParam(a, b_zero);
        printComplex("Result", res);
    }
    catch (const ParamComplexException& e)
    {
        cout << "Caught ParamComplexException: " << e.getMessage() << endl;
        cout << "Parameters were: A = (" << e.getA().re << ", " << e.getA().im << "), "
            << "B = (" << e.getB().re << ", " << e.getB().im << ")" << endl;
    }

    cout << "\nCustom exception: inherited from standard exception" << endl;
    try
    {
        Complex res = divideCustomInherited(a, b_zero);
        printComplex("Result", res);
    }
    catch (const InheritedComplexException& e)
    {
        cout << "Caught InheritedComplexException: " << e.what() << endl;
        cout << "Parameters were: A = (" << e.getA().re << ", " << e.getA().im << "), "
            << "B = (" << e.getB().re << ", " << e.getB().im << ")" << endl;
    }

    cout << "\nFunction with throw() specification" << endl;

    try
    {
        Complex res = divideThrowEmpty(a, b_valid);
        printComplex("Result with valid B in divideThrowEmpty", res);
    }
    catch (...)
    {
        cout << "Caught exception from divideThrowEmpty" << endl;
    }

	cout << "\nResult with zero B in divideThrowEmpty" << endl;
    set_terminate(myTerminate);
    try
    {
        Complex res = divideThrowEmpty(a, b_zero);
        printComplex("Result", res);
    }
    catch (...)
    {
        cout << "Caught exception from divideThrowEmpty" << endl;
    }

    return 0;
}