#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> autoregressive(vector<double> x, double t, double stop){
    
    double meanYT, ytMean, meanTY1, yt1Mean, sumProd, sumDYT1, residualsOut, resAuto;
    vector<double> dyt, dyt1, predictVal, residualsVal;
    // calculate mean
    for(int elements = 0; elements < stop; elements++){
        for(size_t elements = 1; elements < x.size(); elements++){
            // cout<<"YT Elements: "<<x[elements]<<endl;
            meanYT += x[elements];
        }
        for(size_t elements = 0; elements < (x.size()-1); elements++){
            // cout<<"YT-1 Elements: "<<x[elements]<<endl;
            meanTY1 += x[elements];
        }
        ytMean = meanYT / x.size();
        yt1Mean = meanTY1 / x.size();
        
        // Calculate Deviations from YT and YT-1
        for(size_t elements = 1; elements < x.size(); elements++){
            double dytVal = x[elements] - ytMean;
            dyt.push_back(dytVal);
        }

        for(size_t elements = 0; elements < (x.size()-1); elements++){
            double dyt1Val = x[elements] - yt1Mean;
            dyt1.push_back(dyt1Val);
        }
        
        // Summing up the product between deviations of yt and yt-1
        for(size_t elements = 0; elements < dyt.size(); elements++){
            // cout<<"Element 1: "<<dyt[elements]<<" * "<<dyt1[elements]<<endl;
            double prod = dyt[elements] * dyt1[elements];  
            sumProd += prod;  
        }

        // Calculate sum of square of deviation for YT-1
        for(size_t elements = 0; elements < dyt1.size(); elements++){
            double sqrDYT1 = pow(dyt1[elements], 2);
            sumDYT1 += sqrDYT1;
        }

        // Calculating the coefficient Beta
        double beta1 = sumProd / sumDYT1;

        // Calculate Predicted Values
        for(size_t elements = 0; elements < x.size(); elements++){
            double predict = beta1 * x[elements];
            predictVal.push_back(predict);
        }

        // Calculate Residuals or Error Term (Et)
        for(size_t elements = 0; elements < x.size(); elements++){
            double residuals = x[elements] - predictVal[elements];
            residualsOut += residuals;
        }

        double errorTerm = residualsOut / x.size();

        // Calculate Autogressive Model
        if(t >= x.size() && t < stop){
            double out = beta1 * x[t - 1];
            resAuto = out + errorTerm;
            x.push_back(resAuto);
        }
        t = t+1;
    }
    return x;
}