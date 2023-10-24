#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<double> softplus(vector<double> x){
    // log(1 + exp(x))
    vector<double> result;
    for(size_t elements = 0; elements < x.size(); elements++){
        double expRes = log(1 + exp(x[elements]));
        result.push_back(expRes);
    }
    return result;
}