#include "useful_functions.h"

using namespace std;

// conversion of angle from degree to radians
float conversion_degree_to_rad(float x)
{
    return x * M_PI / 180.0;
}

void matrix_multiplication_explicit(double &x, double &y, double &z, double alfa, double beta)
{
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