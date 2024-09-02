#include <iostream>
#include <iomanip>

using namespace std;


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

int main()
{

    double latitude, longitude, point_x = 1, point_y = 0, point_z = 0;
    cout << "insert rotation on z axis for latitude: ";

    latitude = 90 * M_PI / 180.0;
    longitude = 90 * M_PI / 180.0;

    matrix_multiplication_explicit(point_x, point_y, point_z, latitude, longitude);

    cout << point_x << " " << point_y << " " << point_z << endl;
}