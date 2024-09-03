#include <iostream>
#include <vector> //#include <bits/stdc++.h> // use in terminal std=c++11
#include <fstream>
#include <cmath>
#include "useful_functions.h"
using namespace std;

int main(int argc, char *argv[])
{
    fstream cin;
    cin.open(argv[1], ios::in);

    double longitude_degree, latitude_degree;
    double longitude_rad, latitude_rad;
    double point_x, point_y, point_z;

    while (!cin.eof() && !cin.fail())
    {
        cout<<endl<<"#########"<<endl;
        // input longitude and latitude
        cout << "Longitude: ";
        cin >> longitude_degree;

        cout << "Latitude: ";
        cin >> latitude_degree;

        // conversion degree to rad
        longitude_rad = conversion_degree_to_rad(longitude_degree);
        latitude_rad = conversion_degree_to_rad(latitude_degree);

        cout << latitude_degree << " " << longitude_degree << endl;

        // conversion coordinates to latitude/longitude to 3d space
        point_x = 1;
        point_y = 0;
        point_z = 0;
        matrix_multiplication_explicit(point_x, point_y, point_z, longitude_rad, latitude_rad);

        cout << "x: " << point_x << endl;
        cout << "y: " << point_y << endl;
        cout << "z: " << point_z << endl;

        // calculte the cos e sin of the angle between the two vectors
        double cos_angle = point_x / (sqrt(point_x * point_x + point_y * point_y + point_z * point_z));
        double sin_angle = sqrt(point_y * point_y + point_z * point_z) / (sqrt(point_x * point_x + point_y * point_y + point_z * point_z)) * (point_y >= 0 ? 1 : -1);

        // calcultate the anctual angle with arctan
        double actual_angle = atan2(sin_angle, cos_angle);
        cout << actual_angle * 180 / M_PI << endl;

        // lenght of the shadow on earth
        double shadow_lenght = 1 * sin_angle / cos_angle;
        shadow_lenght = shadow_lenght * (shadow_lenght > 0 ? 1 : -1);

        cout << shadow_lenght << endl;
    }

    return 0;
}