#include <iostream>
#include "useful_functions.h"
#include <ctime>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

void print_output(double val){
    const char separator = ' ';
    const int nameWidth = 8;
    const int numWidth = 12;
    cout << left << setw(numWidth) << setfill(separator) << val;

}

void print_table(vector <int> arr1, vector <double> arr2, vector<double> matrix){
    const char separator = ' ';
    const int nameWidth = 8;
    const int numWidth = 12;
    // print lati
    
    cout<<left<<setw(numWidth)<<setfill(separator)<<' ';
    for(int i=0; i<arr1.size(); ++i){
        cout<<left<<setw(numWidth)<<setfill(separator)<<arr1[i]<<endl;
    }
    for(int j=0; j<arr1.size(); ++j){
        for(int i=0; i<arr2.size(); ++i){
            cout<<left<<setw(numWidth)<<setfill(separator)<<arr2[i]<<endl;
        }
    }

}

int main()
{
    

    

    vector<int> lati = {0, 1, 2};
    vector<double> longi = {3, 4, 5};
    vector<double> res = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_table(lati, longi, res);

    return 0;
}