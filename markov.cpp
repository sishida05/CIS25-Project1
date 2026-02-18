#include "markov.h"
#include <iostream>
using namespace std;

string joinWords(const string words[], int startIndex, int count) {
    string result;
    for (int i = 0; i <= count - 1; i++) {
        result += " " + words[startIndex + i];
    }
    return result;
}

int readWordsFromFile(string filename, string words[], int maxWords);

int buildMarkovChain(const string words[], int numWords, int order,
                     string prefixes[], string suffixes[],
                     int maxChainSize);

string getRandomSuffix(const string prefixes[], const string suffixes[],
                            int chainSize, string currentPrefix);

string getRandomPrefix(const string prefixes[], int chainSize);

string generateText(const string prefixes[], const string suffixes[],
                         int chainSize, int order, int numWords);