#include<iostream>
#include<vector>
#include<cctype>
#include<cstring>

using namespace std;

string casefold(char x[]){
    string caseout;
    for(size_t elements = 0; elements < strlen(x); elements++){
        char convLow = tolower(x[elements]);
        caseout += convLow;
    }
    return caseout;
}