// Name: vertezml
// Version: 0.0.4
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double kurtosis(vector<double> x){
    // for(size_t elements = 0; elements < x.size(); elements++){
    //     cout<<"Elements in x: "<<x[elements]<<endl;
    // }
    // Mean of data
    double mean, polyVal, powPolyVal, sqrdSum;
    for(size_t elements = 0; elements < x.size(); elements++){
        double meanCalc = x[elements] / x.size();
        mean += meanCalc;
    }

    powPolyVal = pow(mean, 4);

    // Calculate standard deivation with power raised to 4.
    for(size_t elements = 0; elements < x.size(); elements++){
        double sqrdDiff = x[elements] - powPolyVal;
        // cout<<sqrdDiff<<endl;
        double powSqrDiff = pow(sqrdDiff, 2);
        // cout<<powSqrDiff<<endl;
        sqrdSum += powSqrDiff;
    }
    // Population data
    double popStd = x.size();
    
    // Calculate Population Standard Deviation
    double std = sqrt(sqrdSum / popStd);
    double polyStd = pow(std, 4);

    int out = popStd * polyStd;

    double kurtosisOut = powPolyVal / out;
    double kurtosisVal = kurtosisOut;

    // cout<<"The mean value is: "<<mean<<endl;
    // cout<<"The polynomial value is: "<<powPolyVal<<endl;
    // cout<<"Standard Deviation: "<<sqrdSum<<endl;
    // cout<<"Standard Deviation with power 4: "<<polyStd<<endl;
    // cout<<"Out: "<<out<<endl;
    // cout<<"The kurtosis value is: "<<powPolyVal <<"/"<<out<<"="<<kurtosisOut<<"-"<<"3"<<endl;

    return kurtosisVal;
}