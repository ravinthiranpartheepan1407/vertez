// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double mae(vector<double> actual, vector<double> predict){
    double absSum;
    for(size_t elements = 0; elements < actual.size(); elements++){
        double diff = abs((actual[elements] - predict[elements]));
        cout<<"The difference between actual and predicted values: "<<diff<<endl;
        absSum += diff;
    }
    double maeOut = absSum / actual.size();
    return maeOut;
}