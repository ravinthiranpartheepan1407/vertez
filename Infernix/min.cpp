// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double min(vector<double> x){
    int minValue = x[0];
    for(size_t elements = 0; elements < x.size(); elements++){
        if(x[elements] < minValue){
            minValue = x[elements];
        }
    }
    cout<<"The min value: ";
    return minValue;
}