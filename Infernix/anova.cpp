#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double anova(vector<double> x, vector<double> y){
    // Each Groups: SSW
        // Sum
        double sumX, sumY, meanXVal, meanYVal, sampXMean, sampYMean, xSSWG, ySSWG, xMeanTot, yMeanTot, xObsVal, yObsVal;
        vector<double> obs;
        for(size_t elements = 0; elements < x.size(); elements++){
            sumX += x[elements];
            sumY += y[elements];
        }
        // Mean
        meanXVal = sumX / x.size();
        cout<<"Mean X"<< meanXVal<<endl;
        meanYVal = sumY / y.size();
        cout<<"Mean Y"<< meanYVal<<endl;

        // SSW (Sum of Squares within groups) = Sum(Square(Sample - Mean))
        for(size_t elements = 0; elements < x.size(); elements++){
            double diff = x[elements] - meanXVal;
            double sqr = pow(diff, 2);
            xSSWG += sqr;
        }
        for(size_t elements = 0; elements < y.size(); elements++){
            double diff = y[elements] - meanYVal;
            double sqr = pow(diff, 2);
            ySSWG += sqr;
        }

        double sswg = xSSWG + ySSWG;
        cout<<"The Sum of Square within group: "<<sswg<<endl;

    // Each Groups: TSS (Total Sum of Squares):
        // Mean of all observations
        for(size_t elements = 0; elements < x.size(); elements++){
            xMeanTot += x[elements];
            yMeanTot += y[elements];
        }
        double sizeXY = x.size() + y.size();
        double meanTotObs = (xMeanTot + yMeanTot) / sizeXY;
        cout<<"TSS Mean: "<<meanTotObs<<endl;
        // observation[index] - mean, Square (observation[index] - mean), and Sum(Square(Observation[index] - mean))
        for(size_t elements = 0; elements < x.size(); elements++){
            double xObs = x[elements] - meanTotObs;
            double sqr = pow(xObs, 2);
            xObsVal += sqr;
        }
        for(size_t elements = 0; elements < y.size(); elements++){
            double yObs = y[elements] - meanTotObs;
            double sqr = pow(yObs, 2);
            yObsVal += sqr;
        }
        double tss = xObsVal + yObsVal;
        cout<<"The total sum of squares is: "<<tss<<endl;

    // Calculate Sum of Squares between groups
        // Sum of Squares between groups = Total sum of squares - Sum of squares within groups
        double xMeanSSBG = meanXVal - meanTotObs;
        // cout<<"xMeanSSBG: "<<meanXVal<<" - "<<meanTotObs<<": "<<xMeanSSBG<<endl;
        double yMeanSSBG = meanYVal - meanTotObs;
        // cout<<"yMeanSSBG: "<<meanYVal<<" - "<<meanTotObs<<": "<<yMeanSSBG<<endl;
        double ssBG = (pow(xMeanSSBG,2) + pow(yMeanSSBG,2))*x.size();
        cout<<"The Sum of Squares between groups: "<<ssBG<<endl;
        cout<<"The total sum of square: "<<tss<<" = "<<"SSBG: "<<ssBG<<" + "<<"ssWG: "<<sswg<<endl;
        // Total sum of squares = Sum of Squares between groups + Sum of squares within groups

    // Final Calculations
        // degress of freedom - 1 which is (total no.of groups) - 1
        // a = Sum of Squares between group / degrees of freedom 
        double finalSSBG = ssBG / 1;

        // degrees of freedom = total observations - total no.of groups
        // b = Sum of squares within groups / degrees of freedom
        double finalSSWG = sswg / ((x.size()+y.size())-3);
        double res = finalSSBG / finalSSWG;
        cout<<"Before F-Statistics: "<<"F("<<finalSSBG<<","<<finalSSWG<<")"<<"is: "<<res<<endl;
        // Refer F-Statistics
        // Consider degrees of freedom from numerator from Horizontal perspective which is SSBG
        // Consider degrees of freedom from numerator from Vertical perspective which is SSWG
        // In this case the degrees of freedom in horizontal perspective is 1 (Groups - 1)
        // In this case the degrees of freedom in horizontal perspective is 7 (Total observations - 3)
        return res;
}