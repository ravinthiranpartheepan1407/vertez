#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> softmax(vector<double> x){
    vector<double> expoNom, expoResult;
    double expoSum;
    for(size_t elements = 0; elements < x.size(); elements++){
        double expo = exp(x[elements]);
        expoNom.push_back(expo);
    }
    for(size_t elements = 0; elements < x.size(); elements++){
        double expo = exp(x[elements]);
        expoSum += expo;
    }
    for(size_t elements = 0; elements < expoNom.size(); elements++){
        double expo = (expoNom[elements]) / expoSum;
        expoResult.push_back(expo);
    } 
    return expoResult;
}

int main(){
    vector<double> x;
    vector<double> out = softmax(x);
    for(size_t elements = 0; elements < x.size(); elements++){
        cout<<"The softmax value is: "<<out[elements]<<endl;
    }
}