#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> pca(vector<double> x, vector<double> y, int features, int samples){
    // Compute Mean of X
    vector<double> eVecX, eVecY, normVecX, normVecY, pcaOut;
    double meanX, meanY, covX, covY, covXY;
    for(size_t elements = 0; elements < x.size(); elements++){
        meanX += x[elements];
    }
    // Compute Mean of Y
    for(size_t elements = 0; elements < y.size(); elements++){
        meanY += y[elements];
    }

    double xMean = meanX / x.size();
    double yMean = meanY / y.size();

    // Covariance of all ordered pairs (x)
    for(size_t elements = 0; elements < x.size(); elements++){
        double xCov = (x[elements] -xMean);
        double xCovPow = pow(xCov, 2);
        covX += xCovPow;
    }

    // Covariance of all ordered pairs (x,y)
    for(size_t elements = 0; elements < x.size(); elements++){
        double xyCov = (x[elements] - xMean) * (y[elements] - yMean);
        covXY += xyCov;
    }

    // Covariance of all order pairs in Y
    for(size_t elements = 0; elements < y.size(); elements++){
        double yCov = y[elements] - yMean;
        double yCovPow = pow(yCov, 2);
        covY += yCovPow;
    }

    double xCovar = covX / (x.size() - 1);
    double yCovar = covY / (y.size() - 1);
    double xyCovar = covXY / (y.size() - 1);
    double yxCovar = xyCovar;

    // Computing Eigen Values of covars with 2x2 identity matrix (Quadratic)
    double lamSqr = 1;
    double lam = xCovar + yCovar;
    double constant = (xCovar * yCovar) - (xyCovar * yxCovar);
    // Using Quadratic Equation
    double negQuadSqrt = (-(-lam)) - (sqrt((pow(lam, 2)) - (4 * lamSqr * constant)));
    double posQuadSqrt = (-(-lam)) + (sqrt((pow(lam, 2)) - (4 * lamSqr * constant)));
    double eigenX = posQuadSqrt / (2 * lamSqr);
    double eigenY = negQuadSqrt / (2 * lamSqr);

    // Eigen Vector of X and Y
    // We cosniders eigen val with max value
    if(eigenX > eigenY){
        double vecXCal = (xCovar - eigenX);
        vector<double> eigVecX = {(-(xyCovar)), vecXCal};
        for(size_t elements = 0; elements < eigVecX.size(); elements++){
            eVecX.push_back(eigVecX[elements]);
        }
        // Normalize eigen vector X
        for(size_t elements = 0; elements < eVecX.size(); elements++){
            double sqrtVecX = sqrt((pow(eVecX[0],2)) + (pow(eVecX[1],2)));
            double calcVecX = eVecX[elements] / sqrtVecX;
            normVecX.push_back(calcVecX);
        }
        // Deriving New Dataset
        for(size_t elements = 0; elements < x.size(); elements++){
            double xDiffCalc = x[elements] - xMean;
            double yDiffCalc = y[elements] - yMean;
            vector<double> diffCalc = {xDiffCalc, yDiffCalc};
            double newXDat = (normVecX[0] * xDiffCalc) + (normVecX[1] * yDiffCalc);
            pcaOut.push_back(newXDat);
        }
    }else{
        double vecYCal = yCovar - eigenY;
        vector<double> eigVecY = {(-(yxCovar)), vecYCal};
        for(size_t elements = 0; elements < eigVecY.size(); elements++){
            eVecY.push_back(eigVecY[elements]);
        }
        // Normalize eigen vector Y
        for(size_t elements = 0; elements < eVecY.size(); elements++){
            double sqrtVecY = sqrt((pow(eVecY[0],2)) + (pow(eVecY[1],2)));
            double calcVecY = eVecY[elements] / sqrtVecY;
            normVecY.push_back(calcVecY);
        }
    }
    return pcaOut;
}