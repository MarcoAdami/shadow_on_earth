#include "useful_functions.h"

using namespace std;

// round down to n significant figures
double round_down(double k)
{
    // n = 6
    double sign_figures = 1000000;
    k = trunc(k * sign_figures) / sign_figures;
    return k;
}

// conversion of angle from degree to radians
float conversion_degree_to_rad(float x)
{
    return x * M_PI / 180.0;
}

void latitude_longitude_transformation(double &x, double &y, double &z, double alfa, double beta)
{
    /*
    This is the rotation matrix around the y-axis, used for the longitude rotation
    R_y =   [cos(Ø),    0   sin(Ø)]
            [0,         1,      0]
            [-sin(Ø),   0,  cos(Ø)]

    This is the rotation matrix around the z-axis, used for the latitude rotation
    R_z =   [cos(Ø), -sin(Ø), 0]
            [sin(Ø), cos(Ø), 0]
            [0,     0,      1]

    First at v(1,0,0) is applied the R_y rotation and then the R_z, other orders don't give the same result.
    For simplicity I used the explicit formula of this multiplication down here.
    */
    double x1, y1, z1;

    // defining the explicit furmula for the rotation aroud the y and x axis
    x1 = cos(beta) * cos(alfa) * x - cos(beta) * sin(alfa) * y + sin(beta) * z;
    y1 = sin(alfa) * x + cos(alfa) * y;
    z1 = -sin(beta) * cos(alfa) * x - sin(beta) * sin(alfa) * y + cos(beta) * z;

    x = round_down(x1);
    y = round_down(y1);
    z = round_down(z1);
}

void earth_axis_transformation(double &x, double &y, double &z)
{
    // how to transform coordinates due to earth axis inclination
    /*
    - Simple case:
        Suppose that you are at coordinates (0° N,0° E), its noon, during the solstice of summer in the boreal emisphere.
        In this case to account the earth'axis inclination you should substract -23.44° to your latitude.
        The subtraction could be described as a rotation around the Z-axis of 23.44°.
    - Harder case:
        During the year earth axis rotate, so we have to find the right axis to rotate the earth.
        In summer it's the Z-axis represented as the vector (0,0,1),
        but avery day the vector will be subjected to a slightly change due to earth revolution movement.
    */

    // ATTENTION: later it will be needed to consider imprecision of the year
    //
    const double earth_revolution_per_day_D = 360 / 365.25;
    const double earth_revolution_per_day_R = conversion_degree_to_rad(earth_revolution_per_day_D);

    // days passed from the summer solstice
    int days_passed = 360;

    // rotation
    double angle_rotation = days_passed * earth_revolution_per_day_R;

    // rotation of the vector (0,0,1) using the R_y matrix
    x = sin(angle_rotation);
    z = cos(angle_rotation);
}