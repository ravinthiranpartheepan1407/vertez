#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double samplevar(vector<double> x){
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
    double sampleDat = (x.size())-1;
    double varianceOut = sqrdSum / sampleDat;
    cout<<"The variance is: ";
    return varianceOut;
}