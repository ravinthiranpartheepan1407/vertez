// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

double median(vector<double> input){
    double medianVal;
    for(size_t elements = 0; elements < input.size(); elements++){
        sort(input.begin(), input.end());
        cout<<"The sorted values are: "<<input[elements]<<endl;
        if(input.size() % 2 == 0){
            double out = round((input.size() / 2));
            cout<<"Prev Index: "<<input[out]<<endl;
            double next = round((input.size() / 2) - 1); 
            cout<<"Prev Index: "<<input[next]<<endl;
            double medn = (input[out]+input[next])/2;
            medianVal = medn;
        }else{
            double out = round((input.size() / 2));
            double medn = (input[out]);
            medianVal = medn;
        }
    }
    cout<<"The median value is: ";
    return medianVal;
}