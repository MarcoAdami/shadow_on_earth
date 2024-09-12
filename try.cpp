#include <iostream>
#include "useful_functions.h"
#include <chrono>
#include <cmath>

using namespace std;
int main()
{
    double x=0, y=0, z=1;
    const double earth_revolution_per_day_D = 360 / 365.25;
    const double earth_revolution_per_day_R = conversion_degree_to_rad(earth_revolution_per_day_D);

    // days passed from the summer solstice
    double days_passed = 183.125;

    // rotation
    double angle_rotation = days_passed * earth_revolution_per_day_R;

    // rotation of the vector (0,0,1) using the R_y matrix
    x = sin(angle_rotation);
    z = cos(angle_rotation);

    x = round_down(x);
    y = round_down(y);
    z = round_down(z);

    cout<<x<<" "<<y<<" "<<z<<" "<<days_passed;

    return 0;
}