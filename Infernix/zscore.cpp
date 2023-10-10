// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> zscore(vector<double> x){
    vector<double> stdOut;
    double mean, sqrdSum, stdCalc;
    // Mean Calculation
    for(size_t elements = 0; elements < x.size(); elements++){
        double meanCalc = x[elements] / x.size();
        mean += meanCalc;
    }
    // Standard Deviation Calculation
    for(size_t elements = 0; elements < x.size(); elements++){
        double sqrDiff = x[elements] - mean;
        double powSqrDiff = pow(sqrDiff, 2);
        // cout<<"Sqrd Difference: "<<x[elements]<<" "<<"-"<<" "<<mean<<" :"<<powSqrDiff<<endl;
        sqrdSum += powSqrDiff;
        // cout<<"Squared Sum: "<<sqrdSum<<endl;;
        double std = sqrdSum / x.size();
        // cout<<"Std: "<<std<<endl;
        double sqrtStd = sqrt(std);
        // cout<<"Sqrt of Std: "<<sqrtStd<<endl;
        stdCalc = sqrtStd;
        // cout<<"Standard Deviation: "<<stdCalc<<endl;
    }
    for(size_t elements = 0; elements < x.size(); elements++){
        double out = (x[elements] - mean) / stdCalc;
        cout<<"Result is: "<<out<<endl;
        stdOut.push_back(out);
    }
    cout<<"Mean: "<<mean<<endl;
    return stdOut;
}

// int main(){    
//     vector<double> x;
//     vector<double> out = zscore(x);
//     for(size_t elements = 0; elements < x.size(); elements++){
//         cout<<"Z-Score Normalization is: "<<out[elements]<<endl;
//     }
// }