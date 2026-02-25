#include "markov.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {

    srand(time(0));
    
    string fileName;
    cout << "Please enter a filename: " << endl;
    cin >> fileName;

    ofstream newFile(fileName);
    newFile << "This is the test file that must contain words!" << endl;
    newFile << "This is another line of words that are in this file!" << endl;
    newFile.close();

    int order;
    cout << "Please enter the order (1-3): " << endl;
    cin >> order;
        if (order < 1 || order > 3) {
            return 1;
        }

    int wordNum;
    cout << "Please enter the number of words: " << endl;
    cin >> wordNum;
    
    string words[wordNum], prefixes[10000], suffixes[10000];
    
    // Reading words from the file
    int count = readWordsFromFile(fileName, words, 1000);
    cout << "Read " << count << " words" << endl;
    for (int i = 0; i < 10 && i < count; i++) {
    cout << words[i] << endl;
    }

    // 
    
    int chainSize = buildMarkovChain(words, count, 1, prefixes, suffixes, 10000);
    for (int i = 0; i < 20 && i < chainSize; i++) {
    cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << endl;
    }

    // 
    for (int i = 0; i < 10; i++) {
    cout << getRandomSuffix(prefixes, suffixes, chainSize, "the") << endl;
}

    // 
    for (int i = 0; i < 5; i++) {
    cout << getRandomPrefix(prefixes, chainSize) << endl;
}

string output = generateText(prefixes, suffixes, chainSize, 1, 20);
cout << output << endl;


    return 0;
}