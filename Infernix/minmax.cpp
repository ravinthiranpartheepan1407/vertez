#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> minmax(vector<double> x){
    double minValue = x[0];
    double maxValue = 0;
    double nom;
    
    vector<double> minmaxRes;

    for(size_t elements = 0; elements < x.size(); elements++){
        if(x[elements] < minValue){
            minValue = x[elements];
        }
    }
    // cout<<"The Min value is: "<<minValue<<endl;

    for(size_t elements = 0; elements < x.size(); elements++){
        if(x[elements]>maxValue){
            maxValue = x[elements];
        }
    }
    // cout<<"The max value is: "<<maxValue<<endl;
    // cout<<"-----------"<<endl;
    
    for(size_t elements = 0; elements < x.size(); elements++){
        double nominator = x[elements] - minValue;
        // cout<<"Nominator Val: "<<x[elements] <<"-"<< minValue<<" "<<":"<<" "<<nominator<<endl; 
        // cout<<"The Diff Max Min val is: "<<(maxValue - minValue)<<endl;
        double minmaxOut = nominator / (maxValue - minValue);
        // cout<<"The minmax value is: "<<minmaxOut<<endl;
        // cout<<"-----------"<<endl;    
        minmaxRes.push_back(minmaxOut);
        // cout<<"Min Max Value: "<<minmaxRes[elements]<<endl;
    }
    return minmaxRes;
}

// int main(){
//     vector<double> x;
//     vector<double> out = minmax(x);
//     for(size_t elements = 0; elements < x.size(); elements++){
//         cout<<out[elements]<<endl;
//     }
// }