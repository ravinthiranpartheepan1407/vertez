#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> tanh(vector<double> x){
    vector<double> tanH;
    double expoVal;
    for(size_t elements = 0; elements < x.size(); elements++){
        double expoElements = 1 + exp(2*(-x[elements]));
        double expoDiv = (2 / expoElements) - 1;
        tanH.push_back(expoDiv);
    }
    return tanH;
}