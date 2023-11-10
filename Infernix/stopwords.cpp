#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

vector<string> stopwords(string x){
    vector<string> wordsClust = {"a", "an", "and", "are", "as", "at", "be", "but", "by", "for", "if", "in", "into", "is", "it", "no", "not", "of", "on", "or", "such", "that", "the", "their", "then", "there", "these", "they", "this", "to", "was", "will", "with"};
    vector<string> adjWords, stopWordDat;
    stringstream words(x);
    string splitWords;
    while(words >> splitWords){
        adjWords.push_back(splitWords);
    }
    for(size_t elements = 0; elements < adjWords.size(); elements++){
        if(find(wordsClust.begin(), wordsClust.end(), adjWords[elements]) == wordsClust.end()){
            cout<<"Stop Words Found: "<<adjWords[elements]<<endl;
            stopWordDat.push_back(adjWords[elements]);
        }
    }
    return stopWordDat;
}