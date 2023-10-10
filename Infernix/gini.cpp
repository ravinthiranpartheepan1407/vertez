// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double gini(vector<double> xData, vector<double> yData){
    double sizeX = xData.size();
    double sizeY = yData.size();
    double partX = sizeX/(sizeX+sizeY);
    double partY = sizeY/(sizeX+sizeY);
    double giniXSquare = pow(partX, 2);
    double giniYSquare = pow(partY, 2);
    double ginIndex = 1 - (giniXSquare + giniYSquare);
    return ginIndex;
}
