// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double samplecovar(vector<double> x, vector<double> y){
    double xMean, yMean, xyCovar;
    for(size_t elements = 0; elements < x.size(); elements++){
        double meanX = x[elements] / x.size();
        xMean += meanX;
    }
    for(size_t elements = 0; elements < y.size(); elements++){
        double meanY = y[elements] / y.size();
        yMean += meanY;
    }
    for(size_t elements = 0; elements < x.size(); elements++){
        double xyDiff = (x[elements] - xMean) * (y[elements] - yMean);
        xyCovar += xyDiff;
    }
    int size = (x.size()) - 1;
    double covarianceOut = xyCovar / size;
    cout<<"X Mean: "<<xMean<<endl;
    cout<<"Y Mean: "<<yMean<<endl;
    cout<<"XY Covar Diff: "<<xyCovar<<endl;
    return covarianceOut;
}