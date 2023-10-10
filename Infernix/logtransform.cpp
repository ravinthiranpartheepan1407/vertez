// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> logtransform(vector<double> x){
    vector<double> logOut;
    for(size_t elements = 0; elements < x.size(); elements++){
        double logRes = log(x[elements]);
        logOut.push_back(logRes);
    }
    return logOut;
}

// int main(){
//     vector<double> x;
//     vector<double> out = logtransform(x);
//     for(size_t elements = 0; elements < x.size(); elements++){
//         cout<<"The log value is: "<<out[elements]<<endl;
//     }
// }