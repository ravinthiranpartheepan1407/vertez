#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double rmsle(vector<double> actual, vector<double> predict){
    double rmseSum;
    for(size_t elements = 0; elements < actual.size(); elements++){
        double diff = pow((actual[elements] - predict[elements]), 2);
        cout<<"The difference between actual and predicted values: "<<diff<<endl;
        rmseSum += diff;
    }
    double rmseOut = rmseSum / actual.size();
    double sqRmse = sqrt(rmseOut);
    double sqRmsle = log(sqRmse);
    return sqRmsle;
}
