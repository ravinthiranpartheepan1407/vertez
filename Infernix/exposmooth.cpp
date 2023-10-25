#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> exposmooth(vector<double> x, double alpha){
    // SES_t = α * Y_t + (1 - α) * SES_(t-1)
    vector<double> expoSmooth={x[0]};
    int fStep = 1;
    int bStep = 0;
    for(size_t elements = 0; elements < x.size(); elements++){
        double alphAct = alpha * x[fStep]; // 0.2 * 10, 0.2 * 20, 0.2 * 30,....
        double smoothF = (1-alpha) * expoSmooth[elements];
        cout<<"AplhaAct: "<<alphAct<<" + "<<smoothF<<endl;
        double outF = alphAct + smoothF;
        expoSmooth.push_back(outF);
        fStep = fStep + 1;
        bStep = bStep - 1;
    }
    return expoSmooth;
}