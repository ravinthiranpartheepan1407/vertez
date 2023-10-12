#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> vrange(int start, int stop, int step){
    vector<double> vrangeContainer;
    int stack = start;
    for(int elements = start; elements < stop; elements++){
        if(stack < stop){
            vrangeContainer.push_back(stack);
            stack = stack + step;
        }else{
            break;
        }
    }
    return vrangeContainer;
}