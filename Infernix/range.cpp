#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int range(vector<double> x){
    int maxValue = 0;
    int minValue = x[0]; 
    for(size_t elements = 1; elements < x.size(); elements++){
        if(x[elements] > maxValue){
            maxValue = x[elements];
        }
    }
    for(size_t elements = 0; elements < x.size(); elements++){
        if(x[elements] < minValue){
            minValue = x[elements];
        }
    }
    int rangeOut = maxValue - minValue;
    cout<<"The max value is: "<<maxValue<<endl;
    cout<<"The min value is: "<<minValue<<endl;
    return rangeOut;
}