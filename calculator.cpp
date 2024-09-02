#include <iostream>
#include <vector> //#include <bits/stdc++.h> // use in terminal std=c++11
#include <fstream>
#include <cmath>
#include "useful_functions.h"
using namespace std;

int main()
{
    double longitude_degree, latitude_degree;
    double longitude_rad, latitude_rad;
    double point_x, point_y, point_z;

    while (true)
    {
        // input longitude and latitude
        cout << "Longitude: ";
        cin >> longitude_degree;

        cout << "Latitude: ";
        cin >> latitude_degree;

        // conversion degree to rad
        longitude_rad = conversion_degree_to_rad(longitude_degree);
        latitude_rad = conversion_degree_to_rad(latitude_degree);

        cout << longitude_rad << " " << latitude_rad << endl;

        // conversion coordinates to latitude/longitude to 3d space
        point_x = 1;
        point_y = 0;
        point_z = 0;
        matrix_multiplication_explicit(point_x, point_y, point_z, longitude_rad, latitude_rad);

        cout << "x: " << point_x << endl;
        cout << "y: " << point_y << endl;
        cout << "z: " << point_z << endl;
    }

    return 0;
}