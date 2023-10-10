#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double entropy(vector<double> xData, vector<double> yData){
    double deltaS = 0;
    vector<double> xCalcHS, yCalcHS;
    double sizeX = xData.size();
    double sizeY = yData.size();
    double partX = sizeX/(sizeX+sizeY);
    double partY = sizeY/(sizeX+sizeY);
    double xCalc = -((partX) * log2(partX));
    double yCalc = (partY) * log2(partY);
    double hS = xCalc - yCalc;
    deltaS += hS;    
    return deltaS;
}