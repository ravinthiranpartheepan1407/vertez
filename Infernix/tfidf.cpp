#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

vector<double> tfidf(char doc[][100], int docCount, string word) {
    vector<double> tfidfRes;
    for (int docIndex = 0; docIndex < docCount; docIndex++) {
        char docCopy[100]; // Create a copy for tokenization without modifying the original
        strcpy(docCopy, doc[docIndex]);

        char *docId;
        vector<string> out;
        int frequency = 0;
        docId = strtok(docCopy, " ");

        while (docId != NULL) {
            out.push_back(docId);
            docId = strtok(NULL, " ");
        }

        int totalWords = out.size();
        for (size_t elements = 0; elements < out.size(); elements++) {
            // Convert both word and tokens to lowercase for case-insensitive comparison
            if (word == out[elements]) {
                frequency++;
            }
        }

        // Finding Term Frequency
        // TF = no. of repeat words / total no. of words
        double tf = static_cast<double>(frequency) / totalWords;

        // Calculating IDF
        // Log(total number of documents / (1 + number of documents containing the term))
        double idf = log(docCount / (1.0 + frequency));

        // TF-IDF Score Calculation
        // TF-IDF = TF * IDF
        double tfidfCalc = tf * idf;
        tfidfRes.push_back(tfidfCalc);

        cout << "Document " << docIndex + 1 << ":" << endl;
        cout << "   TF of the word '" << word << "': " << tf << endl;
        cout << "   IDF of the word '" << word << "': " << idf << endl;
        cout << "   TF-IDF Score: " << tfidfCalc << endl;
    }
    return tfidfRes;
}