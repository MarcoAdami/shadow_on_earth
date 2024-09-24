#include <iostream>
#include <vector> //#include <bits/stdc++.h> // use in terminal std=c++11
#include <fstream>
#include <cmath>
#include <iomanip>

#include "useful_functions.h"

using namespace std;

double solve(double latitude_degree, double longitude_degree)
{
    /*
    Defining the system convention:
    - Earth is considered as a sphere
    - X-axis is orizontal and passes through the (0° N, 0° E) cooordinates and its pointed toward you
    - Y-axis is vertical and passes through the poles and its pointed toward the nordth pole
    - Z-axis is orizontal and perpendicular to the other two and its pointed toward west
    - The rays of the sun are considered perfectly orizontal
    */
    double point_x, point_y, point_z;
    double latitude_rad, longitude_rad;

    // starting position
    point_x = 1;
    point_y = 0;
    point_z = 0;

    // conversion degree to rad
    latitude_rad = conversion_degree_to_rad(latitude_degree);
    longitude_rad = conversion_degree_to_rad(longitude_degree);

    // cout << latitude_degree << " " << longitude_degree << endl;

    // coordinates conversion from latitude/longitude to 3d space
    latitude_longitude_transformation(point_x, point_y, point_z, latitude_rad, longitude_rad);
    
    // DEBUG
    //printf("Lat_long transformation: (%f, %f, %f) \n", point_x, point_y, point_z);


    // considering eart axis inclination
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
    shadow_lenght = shadow_lenght*(point_x<0 ? -1 : 1);

    shadow_lenght = round_down(shadow_lenght);
    return shadow_lenght;
}

int main(int argc, char *argv[])
{
    fstream cin, output;
    cin.open(argv[1], ios::in);
    output.open("output.txt", ios::out);

    double longitude_degree, latitude_degree;
    double longitude_rad, latitude_rad;
    double res;

    // test from file
    // while (cin >> latitude_degree && cin >> longitude_degree)
    // {
    //     cout << endl
    //          << "#########" << endl;
    //     cout << "Latitude: " << latitude_degree << endl;
    //     cout << "Longitude: " << longitude_degree << endl;

    //     res = solve(latitude_degree, longitude_degree, night);

        
    //     if(res>=0){
    //         printf("Shadow lenght: %f", res);
    //     }else{
    //         printf("It's night go to bed");
    //     }
        
    // }

    // add table of coordinates and print it
    int arr_long[9] = {-90, -60, -45, -30, 0, 30, 45, 60, 90};
    int arr_lat[9] = {90, 60, 45, 30, 0, -30, -45, -60, -90};
    const char separator = ' ';
    const int nameWidth = 8;
    const int numWidth = 12;

    for (int i = 0; i < 9; ++i)
    {
        // cout << arr_lat[i] << ": ";
        for (int j = 0; j < 9; ++j)
        {
            res = solve(arr_lat[i], arr_long[j]);
            output << left << setw(numWidth) << setfill(separator) << res;

        }
        output << endl;
    }

    return 0;
}