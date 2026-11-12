#include <iostream>
#include <vector>
#include <iomanip>
#include "Triangles.h"
using namespace std;

int main() 
{
   cout << fixed << setprecision(2);

    try {
        vector<unique_ptr<Triangle>> triangles;

        triangles.push_back(make_unique<VertexTriangle>(Point{ 0, 1 }, Point{ 0, 6 }, Point{ 8, 0 }));
        triangles.push_back(make_unique<VertexTriangle>(Point{ 4, 3 }, Point{ 4, 0 }, Point{ 0, 3 }, MedianBases{}));
        triangles.push_back(make_unique<SideTriangle>(13.0, 14.0, 15.0));
        triangles.push_back(make_unique<RightTriangle>(3.0, 4.0));

        for (const auto& tri : triangles) 
        {
            tri->printInfo();
            cout << "Medians m_a = " << tri->getMedian(1) << ", m_b = " << tri->getMedian(2) << ", m_c = " << tri->getMedian(3) << "\n";
            cout << "Midline (parallel to side a) = " << tri->getMidline(1) << "\n";
            cout << "Area S = " << tri->getArea() << "\n";
            cout << "Inradius r = " << tri->getInradius() << "\n";
            cout << "Circumradius R = " << tri->getCircumradius() << "\n" << endl;
        }
    }
    catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}