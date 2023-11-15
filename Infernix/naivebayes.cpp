#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> naivebayes(vector<double> input, vector<double> x, vector<double> y, vector<string> classes, int event){
    // Calculate Probability of X
    double sumX, sumY;
    for(size_t elements = 0; elements < x.size(); elements++){
        sumX += x[elements];
    }
    for(size_t elements = 0; elements < x.size(); elements++){
        cout<<"The probability of each Index in X: "<<x[elements]<<" / "<<sumX<<endl;
    }
    cout<<"The total sum of X classifier: "<<sumX<<endl;

    // Calculate Probability of Y
    for(size_t elements = 0; elements < y.size(); elements++){
        sumY += y[elements];
    }
    for(size_t elements = 0; elements < y.size(); elements++){
        cout<<"The Probability of each Index in Y: "<<y[elements]<<" / "<<sumY<<endl;
    }
    cout<<"The total sum of Y classifier: "<<sumY<<endl;

    // Print Probability X and Y Table
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Total Probaility of X: "<<x.size()<<" / "<<sumX<<endl;
    cout<<"Total Probaility of Y: "<<y.size()<<" / "<<sumY<<endl;
    cout<<"-------------------------------------------------------"<<endl;

    // Calculate Probability of a event
    double probCondA = x[event] / sumX; // Class A -> X and Event 
    double probCondB = y[event] / sumY; // Class B -> Y and Event
    cout<<"The Probability Class A with Event: "<<probCondA<<endl;
    cout<<"The Probability Class B with Event: "<<probCondB<<endl;

    // Normalize the Result
    double normProbA = probCondA / (probCondA + probCondB);
    double normProbB = probCondB / (probCondB + probCondA);
    int probSet = static_cast<int>(normProbA + normProbB);
    cout<<"The Normalized Probability Class A with Event: "<<normProbA<<endl;
    cout<<"The Normalized Probability Class B with Event: "<<normProbB<<endl;    
    cout<<"The Total Probability Value is: "<<probSet<<endl;
    
    // Test Conditions and Prediction
    if((normProbA > normProbB) && probSet == 1){
        cout<<"The Chosen Event: "<<x[event]<<" and "<<y[event]<<" belongs to: "<<"ClassA"<<endl;
    }else{
        cout<<"The Chosen Event: "<<x[event]<<" and "<<y[event]<<" belongs to: "<<"ClassB"<<endl;
    }
    vector<double> res = {normProbA,normProbB};
    return res;
}