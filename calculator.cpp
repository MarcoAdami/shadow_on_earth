#include <iostream>
#include <vector> //#include <bits/stdc++.h> // use in terminal std=c++11
#include <fstream>
#include <cmath>
using namespace std;

float conversion_degree_to_rad(float x){
    return x*M_PI/180;
}

int main()
{
    float longitude_degree, latitude_degree;
    float longitude_rad, latitude_rad;
    float point_x, point_y, point_z;

    while(true){
        // input longitude and latitude
        cout << "Longitude: ";
        cin >> longitude_degree;

        cout << "Latitude: ";
        cin >> latitude_degree;

        point_x = 1;
        point_y = 0;
        point_z = 0;

        // conversion degree to rad
        longitude_rad = conversion_degree_to_rad(longitude_degree);
        latitude_rad = conversion_degree_to_rad(latitude_degree);

        // cout<<longitude_rad<<" "<<latitude_rad<<endl;
    }
    


    return 0;
}