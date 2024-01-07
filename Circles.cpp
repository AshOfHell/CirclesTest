// Circles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <random>
#include <algorithm>
#include <array>
#include "Circles.h"

using namespace std;

int main()
{
    //random numbers starts here:
    random_device RD;   // non-deterministic generator
    mt19937 gen(RD());  // to seed mersenne twister.
    uniform_real_distribution<float> Radi(0, 100); // distribute results between numbers inclusive.    
    uniform_real_distribution<float> Ang(-360, 360); 
    uniform_int_distribution<> ArrSize(1, 100);
    
    float AngleRad = Ang(gen) * M_PI / 180;
    Circle MyCircle{ Radi(gen) };
    int ArraySize = ArrSize(gen);

    //Array as a vector
    vector<Circle> vArray;
    cout << "Radius of each circles in random vector: " << endl;
    for (int i = 0; i < ArraySize; i++)
    {
        vArray.push_back(Circle(Radi(gen)));
        cout << vArray.at(i).Radius << " "; 
    }
    uniform_int_distribution<> RDNum(0, ArraySize);
    int RDNumber = RDNum(gen);
    array<float, 2> Coordinates = vArray.at(RDNumber).GetCoordinates(AngleRad, vArray.at(RDNumber).Radius);
    cout << endl << endl << "In random circle with number " << RDNumber+1 << ":";
    cout << endl << "X = " << Coordinates[0] << ", Y = " << Coordinates[1] << ", Random Angle = " << AngleRad * 180 / M_PI << ", Radius = " << vArray.at(RDNumber).Radius; 
    
    // Select circles with Radius < 50
    vector<Circle> vArray2;
    copy_if(vArray.begin(), vArray.end(), back_inserter(vArray2), [](const auto& a){ return a.Radius < 50; });
    
    // print vArray2 before sort
    cout << endl << endl << "Circles with Radius < 50:" << endl;
    for (int i = 0; i < vArray2.size(); i++)
    {
        cout << vArray2.at(i).Radius << " ";
    }

    sort(vArray2.begin(), vArray2.end(), [](const auto& a, const auto& b)
            { 
                return a.Radius < b.Radius;
            }
        );

    //  print vArray2 after sort
    cout << endl << endl << "Sorted previous vector:" << endl;
    for (int i = 0; i < vArray2.size(); i++)
    {
        cout << vArray2.at(i).Radius << " ";
    }
    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
