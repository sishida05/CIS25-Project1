#include "markov.h"
#include <iostream>
#include <fstream>
using namespace std;

string joinWords(const string words[], int startIndex, int count) {
    string result;
    for (int i = 0; i <= count - 1; i++) {
        result += words[startIndex + i];
    //     if (i < count) {
    //         result += " ";
    //     }
    // }
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
    string pastWords[numWords];
    string print[numWords];
    string newWord, result;

    pastWords[0] = currentPrefix;
    for (int i = 1; i < numWords - order; i++) {
        newWord = getRandomSuffix(prefixes, suffixes, chainSize, currentPrefix);
             if (newWord == "") {
            break;
        }
        
        print[i] = newWord;
        result += newWord + " ";

        if (order == 1) {
            currentPrefix = newWord;
        } else if (order == 2) {
            pastWords[i] = currentPrefix;
            currentPrefix = pastWords[i] + " " + newWord;
        } else if (order == 3) {
            pastWords[i] = currentPrefix;
            currentPrefix = joinWords(pastWords, i-1, i) + " " + newWord;
        }
    }
    return result;
}