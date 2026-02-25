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
    cout << "Please pick one of the following books (Frankenstein, Wuthering Heights, Moby Dick): " << endl;
    cin >> fileName;
        if (fileName != "Frankenstein") {
            return 1;
        } else if (fileName != "Wuthering Heights") {
            return 1;
        } else if (fileName != "Moby Dick") {
            return 1;
        } else {
            ofstream book(fileName);
            book.close();
        }

    int order;
    cout << "Please enter the order (1-3): " << endl;
    cin >> order;
        if (order < 1 || order > 3) {
            return 1;
        }

    int wordNum;
    cout << "Please enter the number of words (1-100,000): " << endl;
    cin >> wordNum;
        if (wordNum < 1 || wordNum > 100000) {
            return 1;
        }
    
    string words[wordNum], prefixes[100000], suffixes[100000];
    
    // Reading words from the file
    int count = readWordsFromFile(fileName, words, 100000);
    cout << "Read " << count << " words" << endl;
    for (int i = 0; i < count; i++) {
    cout << words[i] << endl;
    }

    // Getting the suffixes and prefixes
    int chainSize = buildMarkovChain(words, count, order, prefixes, suffixes, 100000);
    for (int i = 0; i < 20 && i < chainSize; i++) {
    cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << endl;
    }

    string output = generateText(prefixes, suffixes, chainSize, order, wordNum);
    cout << output << endl;


    return 0;
}