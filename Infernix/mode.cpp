#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

void mode(vector<double> x){
    struct
    {
        double element;
        int mode;
    }Count;
    
    for(size_t elements = 0; elements < x.size(); elements++){
        double checkCount = count(x.begin(), x.end(), x[elements]);        
        if(checkCount>1){
            Count.element = x[elements];
            Count.mode = checkCount;
            cout<<"Element: "<<Count.element<<endl;
            cout<<"Mode: "<<Count.mode<<endl;
        }
    }
}