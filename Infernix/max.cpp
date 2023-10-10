#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int max(vector<double> x){
    int maxValue = 0;
    for(size_t elements = 0; elements < x.size(); elements++){
        if(x[elements] > maxValue){
            maxValue = x[elements];
        }
    }
    cout<<"The max value is: ";
    return maxValue;
}
