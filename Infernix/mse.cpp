// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan


#include <iostream>
#include<cmath>
#include<vector>

using namespace std;

double mse(vector<double> actual, vector<double> predict){
    double mseSum;
    for(size_t elements = 0; elements < actual.size(); elements++){
        double diff = pow((actual[elements] - predict[elements]), 2);
        cout<<"The difference between actual and predicted values: "<<diff<<endl;
        mseSum += diff;
    }
    double mseOut = mseSum / actual.size();
    return mseOut;
}