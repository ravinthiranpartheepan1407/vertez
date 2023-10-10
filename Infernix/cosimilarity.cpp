// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<cmath>
#include<vector>
#include<iostream>

using namespace std;

double cosimilarity(vector<double> xData, vector<double> yData){
    double prodSum = 0.0;
    double xProdSum = 0.0;
    double yProdSum = 0.0;
    for(size_t elements = 0; elements < xData.size(); elements++){
        double calc = xData[elements] * yData[elements];
        cout << "The elementwise product between two features: "<< calc << endl;
        prodSum += calc;

        // Squares on each features
        double xSqaure = pow((xData[elements]), 2);
        double ySquare = pow((yData[elements]), 2);

        xProdSum += xSqaure;
        yProdSum += ySquare;
    }
    double calcDenominator = sqrt(xProdSum) * sqrt(yProdSum);
    if((prodSum / calcDenominator) == 1){
        cout<<"Two vectors are identical and points in the same direction: "<< " ";
    } else if((prodSum / calcDenominator) < 1 && (prodSum / calcDenominator) > 0){
        cout<<"Two vectors are somewhat similar but not identical: "<< " ";
    } else{
        cout << "Two Vectors are not similar: "<< " ";
    }
    return prodSum / calcDenominator;
}