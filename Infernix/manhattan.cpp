#include<cmath>
#include<vector>
#include<iostream>

using namespace std;

double manhattan(vector<double> &x1data, vector<double> &x2data){
    double sum = 0.0;
    for(size_t elements=0; elements < x1data.size(); elements++){
        sum += abs(x1data[elements] - x2data[elements]);
        cout<< sum<<endl;
    }
    return sum;
}