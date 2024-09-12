#include <iostream>
#include <vector> //#include <bits/stdc++.h> // use in terminal std=c++11
#include <fstream>
#include <cmath>

#include "useful_functions.h"

using namespace std;
using namespace chrono;

double solve(double latitude_degree, double longitude_degree)
{
    /*
    Defining the system convention:
    - Earth is considered as a sphere
    - X-axis is orizontal and passes through the (0° N, 0° E) cooordinates
    - Y-axis is vertical and passes through the polse
    - Z-axis is orizontal and perpendicular to the other two
    - The rays of the sun are considered perfectly orizontal
    */
    double point_x, point_y, point_z;
    double latitude_rad, longitude_rad;

    // latitude rinormalization due to axis earth inclination 23.44°
    latitude_degree = latitude_degree;

    // conversion degree to rad
    latitude_rad = conversion_degree_to_rad(latitude_degree);
    longitude_rad = conversion_degree_to_rad(longitude_degree);

    // cout << latitude_degree << " " << longitude_degree << endl;

    // starting position
    point_x = 1;
    point_y = 0;
    point_z = 0;

    // coordinates conversion from latitude/longitude to 3d space
    latitude_longitude_transformation(point_x, point_y, point_z, latitude_rad, longitude_rad);

    //considering the time

    //considering eart axis inclination
    //...............................//


    // latitude_longitude_traformation(point_x, point_y, point_z, latitude_rad, longitude_rad);

    // cout << "x: " << point_x << endl;
    // cout << "y: " << point_y << endl;
    // cout << "z: " << point_z << endl;

    // calculte the cos e sin of the angle between the two vectors
    double cos_angle = point_x / (sqrt(point_x * point_x + point_y * point_y + point_z * point_z));
    double sin_angle = sqrt(point_y * point_y + point_z * point_z) / (sqrt(point_x * point_x + point_y * point_y + point_z * point_z)) * (point_y >= 0 ? 1 : -1);

    // calcultate the anctual angle with arctan
    // double actual_angle = atan2(sin_angle, cos_angle);
    // cout << actual_angle * 180 / M_PI << endl;

    // lenght of the shadow on earth
    double shadow_lenght = 1 * sin_angle / cos_angle;
    shadow_lenght = shadow_lenght * (shadow_lenght >= 0 ? 1 : -1);

    return shadow_lenght;
}

int main(int argc, char *argv[])
{
    fstream cin;
    cin.open(argv[1], ios::in);

    double longitude_degree, latitude_degree;
    double longitude_rad, latitude_rad;
    double res;

    while (cin >> latitude_degree && cin >> longitude_degree)
    {
        cout << endl
             << "#########" << endl;

        // input longitude and latitude
        cout << "Latitude: " << latitude_degree << endl;

        cout << "Longitude: " << longitude_degree << endl;

        res = solve(latitude_degree, longitude_degree);

        cout << res << endl;
    }

    // add table of coordinates and print it
    // int arr_long[9] = {-90, -60, -45, -30, 0, 30, 45, 60, 90};
    // int arr_lat[9] = {90, 60, 45, 30, 0, -30, -45, -60, -90};

    // for (int i = 0; i < 9; ++i)
    // {
    //     cout << arr_lat[i] << ": ";
    //     for (int j = 0; j < 9; ++j)
    //     {
    //         res = solve(arr_lat[i], arr_long[j]);
    //         cout << res << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}