// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

// Hamming Distance

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int hamming(string xData, string yData){
    int count = 0;
    for(int chars = 0; chars < xData.size(); chars++){
        if(xData[chars] == yData[chars]){
            cout<<"Matched Characters are: "<<xData[chars]<< " "<< "and"<< " "<<yData[chars]<<endl;
        } else{
            cout<<"Unique Characters found: "<< xData[chars]<<" "<<"and"<< " "<<yData[chars]<<endl;
            int calcXCount = sizeof(xData[chars]);
            int calcYCount = sizeof(yData[chars]);
            cout<<"Total unique characters: "<< " "<<calcXCount+calcYCount<<endl;
            count += calcXCount+calcYCount;
        }
    }
    return count;
}