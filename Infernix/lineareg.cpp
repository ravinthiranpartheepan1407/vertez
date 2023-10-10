// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double lineareg(vector<double> xData, vector<double> yData, int x){
    double xMean;
    double yMean;
    vector<double> slopeXVal, slopeYVal;
    double slopeProdXY, SlopeXSq;
    if(xData.size() == yData.size()){
        for(size_t elements = 0; elements < xData.size(); elements++){
            double mean = xData[elements] / xData.size();
            xMean += mean;
        }

        for(size_t elements = 0; elements < yData.size(); elements++){
            double mean = yData[elements] / yData.size();
            yMean += mean;
        }

        // calculate slope (m)
        for(size_t elements = 0; elements < xData.size(); elements++){
            double slopeX = xData[elements] - xMean;
            slopeXVal.push_back(slopeX);
            // cout<<slopeXVal[elements]<<endl;
        }

        for(size_t elements = 0; elements < yData.size(); elements++){
            double slopeY = yData[elements] - yMean;
            slopeYVal.push_back(slopeY);
            // cout<<slopeYVal[elements]<<endl;
        }

        for(size_t elements = 0; elements < xData.size(); elements++){
            double slopeXSqr = xData[elements] - xMean;
            double powSlopeSq = pow(slopeXSqr, 2);
            SlopeXSq += powSlopeSq;
        }

        for(size_t elements = 0; elements < slopeXVal.size(); elements++){
            double slopeProd = slopeXVal[elements] * slopeYVal[elements];
            slopeProdXY += slopeProd;
        }

        double slope = slopeProdXY / SlopeXSq;

        // Calculate Intercept (b)
        double intercept = yMean - (slope * xMean);

        // Linear Regression Analysis
        double regression = (slope * x) + intercept;

        // cout<<"X Mean is: "<<" "<<xMean<<endl;
        // cout<<"Y Mean is: "<<" "<<yMean<<endl;
        // cout<<"Slope prod X and Y is: "<<slopeProdXY<<endl;
        // cout<<"Slope prod sqr X and Y is: "<<SlopeXSq<<endl;
        // cout<<"The slope of X and Y is: "<< " "<<slope<<endl;
        // cout<<"The intercept (B) is: "<<" "<<intercept<<endl;
        // cout<<"The Regression value for the input"<<" "<< x <<" "<<"is: "<<" "<<regression<<endl;
        cout<<"The Regression value for the input"<<" "<< x <<" "<<"is: ";
        return regression;
    }else{
        cout<<"Features are in different shape: ";
        return 0;
    }
}