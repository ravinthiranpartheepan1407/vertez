#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> gradientdescentinter(vector<double> x, vector<double> y, double input, double learning_rate, int itr){
    // y= mx+ b
    // y isthe predicted value
    // x is the number of input,
    // m i sthe slope
    // b is the intercept

    vector<double> slopeRes, interRes;

    for(int iteration = 0; iteration < itr; iteration++){
        double xMean, yMean, prodXY, xyProd, slope, intercept, lsq, mseVal, pdSlope, pdIntercept, slopeNew, interceptNew;
        double pdSlopeSum, pdInterceptSum;
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

        // Mean squared error
        for(size_t elements = 0; elements < predict.size(); elements++){
            double mseDiff = pow((y[elements] - predict[elements]),2);
            cout<<"MSE Values: "<<mseDiff<<endl;
            mseVal += mseDiff;
        }
        double mseOut = mseVal / x.size();

        // Partial Derivatives of 'm' Slope
        for(size_t elements = 0; elements < x.size(); elements++){
            double pdSlopeCalc = x[elements] * (y[elements] - predict[elements]);
            pdSlopeSum += pdSlopeCalc;
        }
        
        pdSlope = -(2 * pdSlopeSum) / x.size();

        // Partial Derivatives of 'b' Intercept
        for(size_t elements = 0; elements < x.size(); elements++){
            double pdInterceptCalc = y[elements] - predict[elements];
            pdInterceptSum += pdInterceptCalc;
        }
        
        pdIntercept = -(2 * pdInterceptSum) / x.size();

        // Update Gradients with learning rate
        slopeNew = slope - (learning_rate * pdSlope);
        interceptNew = intercept - (learning_rate * pdIntercept);

        slopeRes.push_back(slopeNew);
        interRes.push_back(interceptNew);

        cout<<"Mean of X: "<<xMean<<endl;
        cout<<"Mean of Y: "<<yMean<<endl;
        cout<<"Slope: "<<slope<<endl;
        cout<<"Intercept: "<<intercept<<endl;
        cout<<"The Predicted values is: "<<lsq<<endl;
        cout<<"Partial Derivative of Slope: "<<pdSlope<<endl;
        cout<<"Partial Derivative of Intercept: "<<pdIntercept<<endl;
        cout<<"The updated slope using gradient and learning rate is: "<<slopeNew<<endl;
        cout<<"The updated intercept using gradient and learning rate is: "<<interceptNew<<endl;
        cout<<"----------------End of Iteration: "<<itr<<" ------------------"<<endl;
    }
    return interRes;
}