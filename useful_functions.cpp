#include "useful_functions.h"

using namespace std;

// conversion of angle from degree to radians
float conversion_degree_to_rad(float x)
{
    return x * M_PI / 180.0;
}

void matrix_multiplication_explicit(double &x, double &y, double &z, double alfa, double beta)
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

    // round down to 3 significant figures
    const int sign_figures = 10000000;
    x = trunc(x1 * sign_figures) / sign_figures;
    y = trunc(y1 * sign_figures) / sign_figures;
    z = trunc(z1 * sign_figures) / sign_figures;
}