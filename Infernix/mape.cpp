#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double mape(vector<double> actual, vector<double> predict){
    double absSum, sumActual;
    for(size_t elements = 0; elements < actual.size(); elements++){
        double diff = abs((actual[elements] - predict[elements]));
        cout<<"The difference between actual and predicted values: "<<diff<<endl;
        sumActual += actual[elements];
        absSum += (diff / sumActual);
    }
    double mapeOut = absSum / actual.size();
    return mapeOut;
}