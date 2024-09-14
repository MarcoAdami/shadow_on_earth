#include <iostream>
#include "useful_functions.h"
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int time_min;
    time_t now;
    struct tm *ptmgm;
    now = time(0);        // UTC
    ptmgm = gmtime(&now); // further convert to GMT presuming now in local
    time_min = ptmgm->tm_hour * 60 + ptmgm->tm_min;

    cout << time_min << endl;

    return 0;
}