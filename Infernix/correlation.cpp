#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double correlation(vector<double> xData, vector<double> yData){
    double xMean;
    double yMean;  

    vector<double> xDiff, yDiff;   
    vector<double> xSq, ySq;
    double nom, denom;

    if(xData.size() == yData.size()){
        // Mean of X and Y
        for(size_t elements = 0; elements < xData.size(); elements++){
            double mean = xData[elements] / xData.size();
            xMean += mean;
        }
        for(size_t elements = 0; elements < yData.size(); elements++){
            double mean = yData[elements] / yData.size();
            yMean += mean;
        }
        // Difference between X and Y
        for(size_t elements = 0; elements < xData.size(); elements++){
            double diffX = xData[elements] - xMean;
            xDiff.push_back(diffX);
            // cout<<xDiff[elements]<<endl;
        }
        for(size_t elements = 0; elements < yData.size(); elements++){
            double diffY = yData[elements] - yMean;
            yDiff.push_back(diffY);
            // cout<<yDiff[elements]<<endl;
        }
        // Square of X and Y and Sqrt on X and Y
        for(size_t elements = 0; elements < xData.size(); elements++){
            double xSqr = xData[elements] - xMean;
            double powXSq = pow(xSqr, 2);
            xSq.push_back(sqrt(powXSq));
        }
        for(size_t elements = 0; elements < yData.size(); elements++){
            double ySqr = yData[elements] - yMean;
            double powySq = pow(ySqr, 2);
            ySq.push_back(sqrt(powySq));
        }

        for(size_t elements = 0; elements < xDiff.size(); elements++){
            double prod = xDiff[elements] * yDiff[elements];
            nom += prod;
        }
        for(size_t elements = 0; elements < xDiff.size(); elements++){
            double prod = xSq[elements] * ySq[elements];
            denom += prod;
        }

        double corr = nom / denom;
        return corr;    
    }else{
        cout<<"Features are in different shape: ";
        return 0;
    }
}