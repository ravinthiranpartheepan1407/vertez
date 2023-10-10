// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double rsquare(vector<double> actual, vector<double> predict){
    
    // Mean Squared Error: Sum of squares of residuals (SSR)
    double mseSum, ssrOut, tssOut;
    double actualMean;

    // Mean of Actual Values
    for(size_t elements = 0; elements < actual.size(); elements++){
        double mean = actual[elements] / actual.size();
        actualMean += mean;
    }

    // Sum of squares of residuals (SSR)
    for(size_t elements = 0; elements < actual.size(); elements++){
        double ssr = pow((actual[elements] - actualMean),2);
        cout<<"The sum of squared residuals: "<<ssr<<endl;
        ssrOut += ssr;
    }

    // Total sum of squares (TSS)
    for(size_t elements = 0; elements < actual.size(); elements++){
        double tss = pow((actual[elements] - predict[elements]),2);
        cout<<"The total sum of squares: "<<tss<<endl;
        tssOut += tss;
    }

    double rSqrOut = 1 - (tssOut/ssrOut);
    return rSqrOut;
}