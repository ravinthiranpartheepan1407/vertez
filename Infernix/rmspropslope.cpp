#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> rmspropslope(vector<double> x, vector<double> y, double input, double learning_rate, double decay, double decRate,double setConst, int itr){
    // y= mx+ b
    // y isthe predicted value
    // x is the number of input,
    // m i sthe slope
    // b is the intercept

    vector<double> slopeRes, interRes;

    for(int iteration = 0; iteration < itr; iteration++){
        double xMean, yMean, prodXY, xyProd, slope, intercept, lsq, mseVal, pdSlope, pdIntercept, slopeNew, interceptNew;
        vector<double> predict;

        // Calculate Mean of Feature 1
        for(size_t elements = 0; elements < x.size(); elements++){
            xMean += x[elements] / x.size();
        }

        // Calculate Mean of Feature 2
        for(size_t elements = 0; elements < y.size(); elements++){
            yMean += y[elements] / y.size();
        }

        // Find Slope 'm'
        for(size_t elements = 0; elements < x.size(); elements++){
            prodXY += (x[elements] - xMean) * (y[elements] - yMean);
            xyProd += pow((x[elements] - xMean),2);
            slope = prodXY / xyProd;
        }

        // Find Intercept 'b
        intercept = yMean - ((slope) * xMean);

        // Least Square Metric
        lsq = (slope * input) + intercept;

        // Iteration
        for(size_t elements = 0; elements < x.size(); elements++){
            double predictVal = (slope * x[elements]) + intercept;
            predict.push_back(predictVal);
        }

        for(size_t elements = 0; elements < predict.size(); elements++){
            cout<<"Predicted Iteration: "<<predict[elements]<<endl;
        }

        // Calculate Gradient Descent with respect to slope and intercept
        // Slope Evaluation
        // Partial Derivatives of 'm' Slope
        for(size_t elements = 0; elements < x.size(); elements++){
            pdSlope = -2 * x[elements] * (y[elements] - predict[elements]);
        }

        // Partial Derivatives of 'b' Intercept
        for(size_t elements = 0; elements < x.size(); elements++){
            pdIntercept = -2 * (y[elements] - predict[elements]);
        }

        // Moving Average of squared gradients for both slope and intercept
        // Typical Decay Rate = 0.9
        double mvSlope = decay * decRate + (1-decay) * pow(pdSlope,2);
        double mvIntercept = decay * decRate + (1-decay) * pow(pdIntercept,2);

        // Update m and b using RMSProp
        double rmsM = slope - (learning_rate / sqrt(mvSlope+setConst)) * pdSlope;
        double rmsB = intercept - (learning_rate / sqrt(mvIntercept+setConst)) * pdIntercept;

        slopeRes.push_back(rmsM);

        cout<<"Mean of X: "<<xMean<<endl;
        cout<<"Mean of Y: "<<yMean<<endl;
        cout<<"Slope: "<<slope<<endl;
        cout<<"Intercept: "<<intercept<<endl;
        cout<<"The Predicted values is: "<<lsq<<endl;
        cout<<"Partial Derivative of Slope: "<<pdSlope<<endl;
        cout<<"Partial Derivative of Intercept: "<<pdIntercept<<endl;
        cout<<"Moving Average of Slope: "<<mvSlope<<endl;
        cout<<"Moving Average of Intercept: "<<mvIntercept<<endl;
        cout<<"RMSProp for Slope: "<<rmsM<<endl;
        cout<<"RMSProp for Intercept: "<<rmsB<<endl;
        cout<<"-------- End of Iteration: "<<itr<<" --------"<<endl;
    }
    return slopeRes;
}