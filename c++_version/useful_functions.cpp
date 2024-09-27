#include "useful_functions.h"

using namespace std;

// round down to n significant figures
double round_down(double k)
{
    // n = 6
    double sign_figures = 10000;
    k = trunc(k * sign_figures) / sign_figures;
    return k;
}

// conversion of angle from degree to radians
float conversion_degree_to_rad(float x)
{
    return x * M_PI / 180.0;
}

double time_transformation()
{
    // how to transform coordinates based on the time of the day
    /*
    Till now we assumed that was always noon at the 0° longitude,
    but now we have to undestand how the earth rotate based on the time.
    Earth rotates 360° in 24h (=24*60 = 1440 min) so the angular velocity is 360/1440 = 0.25°/min.
    So we can get the difference between the Greenwhich time and the noon,
    multiply it by the angular velocity to find the angle to rotate more the point around the Y_Axis.
    */
    const double angular_velocity = 0.25;

    time_t now = time(0);            // UTC
    struct tm *ptmgm = gmtime(&now); // further convert to GMT presuming now in local

    double time_min = ptmgm->tm_hour * 60 + ptmgm->tm_min;
    double time_diff = time_min - 12 * 60;

    double angle_time = time_diff * angular_velocity;
    // cout << time_diff << endl;
    // cout << angle_time << endl;
    angle_time = conversion_degree_to_rad(angle_time);
    return angle_time;
}

void latitude_longitude_transformation(double &x, double &y, double &z, double lati, double longi)
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

    First at v(1,0,0) is applied the R_z rotation and then the R_y, other orders don't give the same result.
    For simplicity I used the explicit formula of this multiplication down here.
    */
    double x1, y1, z1;

    // ADD1: considering the time
    // longi += time_transformation();
    // cout << longi << endl;
    //.........................//

    // defining the explicit furmula for the rotation aroud the y and z axis
    x1 = cos(longi) * cos(lati) * x - cos(longi) * sin(lati) * y + sin(longi) * z;
    y1 = sin(lati) * x + cos(lati) * y;
    z1 = -sin(longi) * cos(lati) * x - sin(longi) * sin(lati) * y + cos(longi) * z;

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