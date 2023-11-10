#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

vector<string> tokenize(string x){
    vector<string> out;
    stringstream splitWords(x);
    string words;
    while(splitWords >> words){
        out.push_back(words);
    }
    return out;
}
