// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

double euclidean(vector<double> xData, vector<double> yData){
    double sum = 0.0;
    for(size_t elements = 0; elements < xData.size(); elements++){
        double distCalc = pow((xData[elements] - yData[elements]), 2);
        sum += distCalc;
        cout<<distCalc<<endl;
    }
    double out = sqrt(sum);
    return out;
}