#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> sigmoid(vector<double> x){
    vector<double> sigmoidOut;
    for(size_t elements = 0; elements < x.size(); elements++){
        double sigmoidDenom = 1 + exp(-x[elements]);
        double sigmoidNom = 1 / sigmoidDenom;
        sigmoidOut.push_back(sigmoidNom);
    }
    return sigmoidOut;
}