#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> movingavg(vector<double> x, int criteria){

   vector<double> result;
    
    for (int elementX = criteria - 1; elementX < x.size(); elementX++) {
        double mvCalc = 0.0;
        
        // Calculate the moving average for the current window
        for (int elementY = 0; elementY < criteria; elementY++) {
            mvCalc += x[elementX - elementY];
            cout<<"MV cacl: "<<x[elementX]<<" "<<" - "<<x[elementY]<<endl;
        }
        
        // Calculate the average and add it to the result vector
        double out = mvCalc / criteria;
        result.push_back(out);
    }
    return result;
}