#include "markov.h"
#include <iostream>
#include <fstream>
using namespace std;

string joinWords(const string words[], int startIndex, int count) {
    string result;
    for (int i = 0; i <= count - 1; i++) {
        result += " " + words[startIndex + i];
    }
    return result;
}

int readWordsFromFile(string filename, string words[], int maxWords) {
    int counter = 0;
    ifstream test ("test.txt");
    if (test.is_open()) {
        while (counter < maxWords && test >> words[counter]) {
            counter++;
        }
    } else {
        return -1;
    }
    test.close();
    return counter;
}

int buildMarkovChain(const string words[], int numWords, int order, string prefixes[], string suffixes[], int maxChainSize) {
    int count = 0;
    for (int i = 0; i < numWords - order - 1; i++) {
        string prefix = joinWords(words, i, order);
        string suffix = words[i + order];
        prefixes[count] = prefix;
        suffixes[count] = suffix;
        count++;
        if (count == maxChainSize) {
            break;
        }
    }
    return count;
}

string getRandomSuffix(const string prefixes[], const string suffixes[],
                            int chainSize, string currentPrefix);

string getRandomPrefix(const string prefixes[], int chainSize);

string generateText(const string prefixes[], const string suffixes[],
                         int chainSize, int order, int numWords);