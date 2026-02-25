#include "markov.h"
#include <iostream>
#include <fstream>
using namespace std;

string joinWords(const string words[], int startIndex, int count) {
    string result;
    for (int i = 0; i <= count - 1; i++) {
        result += words[startIndex + i];
        if (i < count - 1) {
            result += " ";
        }
    }
    return result;
}

int readWordsFromFile(string filename, string words[], int maxWords) {
    int counter = 0;
    ifstream book(filename);
    if (book.is_open()) {
        while (counter < maxWords && book >> words[counter]) {
            counter++;
        }
    } else {
        return -1;
    }
    book.close();
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

string getRandomSuffix(const string prefixes[], const string suffixes[], int chainSize, string currentPrefix) {
    int matchCount = 0;
    for (int i = 0; i <= chainSize-1; i++) {
        if (prefixes[i] == currentPrefix) {
            matchCount++;
            }
        }
        if (matchCount == 0) {
            return "";
    }
    int pick = rand() % matchCount;
    int currentMatch = 0;
    for (int i = 0; i <= chainSize-1; i++) {
        if (prefixes[i] == currentPrefix) {
            if (currentMatch == pick) {
                return suffixes[i];
            }
            currentMatch++;
        }
    }
    return "";
}

string getRandomPrefix(const string prefixes[], int chainSize) {
    int index = rand() % chainSize;
    return prefixes[index];

}

string generateText(const string prefixes[], const string suffixes[],int chainSize, int order, int numWords) {
    string currentPrefix = getRandomPrefix(prefixes, chainSize);
    string result;
    string prefixWords[3];

    string temp;
    
    // Had to look up how to do this
    // As far as I know, we have not learned any method to actually accomplish this
    stringstream ss(currentPrefix);
    int index = 0;
    while (ss >> temp && index < order) {
        prefixWords[index] = temp;
        index++;
    }

    for (int i = 1; i < numWords - order; i++) {
        string newWord = getRandomSuffix(prefixes, suffixes, chainSize, currentPrefix);
             if (newWord == "") {
            break;
        }
        
        result += newWord + " ";
        for (int j = 0; j < order - 1; j++) {
            prefixWords[j] = prefixWords[j + 1];
        }
        prefixWords[order - 1] = newWord;
        currentPrefix = joinWords(prefixWords, 0, order);
    }
    return result;
}