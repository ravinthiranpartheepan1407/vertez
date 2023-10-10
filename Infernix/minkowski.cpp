#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double minkowski(vector<double> xData, vector<double> yData, int p){
    double sum = 0.0;
    double setPow = 1.0/p;
    cout << "Power Value is: " << setPow << endl;
    for(size_t elements = 0; elements < xData.size(); elements++){
        double calc = pow(abs(xData[elements] - yData[elements]), p);
        cout << "Distance Calculation: " << calc << endl;
        sum += calc;
    }
    cout << "Calculated Sum is: "<< sum <<endl;
    double pCalc = pow(sum, setPow);
    return pCalc;
}
