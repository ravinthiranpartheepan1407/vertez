// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void kmeans(vector<double> &x, vector<double> &y, double setCentroidX1, double setCentroidY1, double setCentroidX2, double setCentroidY2, int n){
    vector<double> centroid1, centroid2, clusterx1, clusterx2, clustery1, clustery2;
    double clusterx1Sum, clusterx2Sum,clustery1Sum, clustery2Sum;
    for(int iterate = 0; iterate < n; iterate++){
        for(size_t elements = 0; elements < x.size(); elements++){
            // Centroid 1 Computation
            double distX1 = pow((x[elements] - setCentroidX1),2);
            double distY1 = pow((y[elements] - setCentroidY1), 2);
            double distx1y1 = distX1 + distY1;
            double sqrtDist1 = sqrt(distx1y1);

            centroid1.push_back(sqrtDist1);
        }

        for(size_t elements = 0; elements < y.size(); elements++){
            // Centroid 2 Computation
            double distX2 = pow((x[elements] - setCentroidX2),2);
            double distY2 = pow((y[elements] - setCentroidY2), 2);
            double distx2y2 = distX2 + distY2;
            double sqrtDist2 = sqrt(distx2y2);

            centroid2.push_back(sqrtDist2);
        }

        for(size_t elements = 0; elements < centroid1.size(); elements++){
            cout<<"Centroid 1 values: "<<centroid1[elements]<<endl;
            cout<<"Centroid 2 values: "<<centroid2[elements]<<endl;
            if(centroid1[elements]<centroid2[elements]){
                cout<<"The instance" << " "<< elements << " with min value is"<< " " <<centroid1[elements] << " " << "and it belong to cluster 1"<<endl;
                clusterx1.push_back(x[elements]);
                clustery1.push_back(y[elements]);
            } else{
                cout<<"The instance" << " "<< elements << " with min value is"<< " " <<centroid2[elements] << " " << "and it belong to cluster 2"<<endl;
                clusterx2.push_back(y[elements]);
                clustery2.push_back(y[elements]);
            }
        }

        for(size_t elements = 0; elements < clusterx1.size(); elements++){
            cout<<"Cluster 1 values: "<<clusterx1[elements]<<endl;
            // Centroid X1 Update
            clusterx1Sum += clusterx1[elements];
            double clustX1Out = clusterx1Sum / clusterx1.size();
            setCentroidX1 = clustX1Out;
            // Centroid Y1 Update
            clustery1Sum += clustery1[elements];
            double clustY1Out = clustery1Sum / clustery1.size();
            setCentroidY1 = clustY1Out;
        }
        for(size_t elements = 0; elements < clusterx2.size(); elements++){
            cout<<"Cluster 2 values: "<<clusterx2[elements]<<endl;
            // Centroid X2 Update
            clusterx2Sum += clusterx2[elements];
            double clustYOut = clusterx2Sum / clusterx2.size();
            setCentroidX2 = clustYOut;
            // Centroid Y2 Update
            clustery2Sum += clustery2[elements];
            double clustY2Out = clustery2Sum / clustery2.size();
            setCentroidY2 = clustY2Out;
        }
        cout<<"Updated mean for Cluster 1's X1: "<<setCentroidX1<<endl;
        cout<<"Updated mean for Cluster 1's Y1: "<<setCentroidY1<<endl;
        cout<<"Updated mean for Cluster 2's X2: "<<setCentroidX2<<endl;
        cout<<"Updated mean for Cluster 2's Y2: "<<setCentroidY2<<endl;
        cout<<"-----END OF ITERATION: "<<iterate<<" "<<"-----"<<endl;
    }
}