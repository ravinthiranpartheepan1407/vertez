// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double variance(vector<double> x){
    // Mean Calculation
    double mean, sqrdSum;
    for(size_t elements = 0; elements < x.size(); elements++){
        double meanCalc = x[elements] / x.size();
        mean += meanCalc;
    }
    // Sum of squared difference between x elements and mean
    for(size_t elements = 0; elements < x.size(); elements++){
        double sqrdDiff = x[elements] - mean;
        double powerDiff = pow(sqrdDiff, 2);
        sqrdSum += powerDiff;
    }
    // Sample data observation
    double populateDat = (x.size());
    double varianceOut = sqrdSum / populateDat;
    cout<<"The variance is: ";
    return varianceOut;
}