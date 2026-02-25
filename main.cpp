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
    int bookNum;

    cout << "Select one (1-3): " << endl << endl;
    cout << "Number\tBook" << endl;
    cout << "-------------------------------" << endl;
    cout << "1\tFrankenstein" << endl;
    cout << "2\tWuthering Heights" << endl;
    cout<< "3\tMoby Dick" << endl;
    
    cin >> bookNum;
        if (bookNum == 1) {
            fileName = "Frankenstein.txt";
        } else if (bookNum == 2) {
            fileName = "Wuthering Heights.txt";
        } else if (bookNum == 3) {
            fileName = "Moby Dick.txt";
        } else {
            return 1;
        }
            
    int order;
    cout << endl << "Please enter the order (1-3): " << endl;
    cin >> order;
        if (order < 1 || order > 3) {
            return 1;
        }

    int wordNum;
    cout << endl << "Please enter the number of words (1-100,000): " << endl;
    cin >> wordNum;
        if (wordNum < 1 || wordNum > 100000) {
            return 1;
        }
    
    string words[100000];
    string prefixes[wordNum], suffixes[wordNum];
    
    
    // Reading words from the file
    int count = readWordsFromFile(fileName, words, wordNum);
    cout << "Read " << count << " words" << endl;

    // Getting the suffixes and prefixes
    int chainSize = buildMarkovChain(words, count, order, prefixes, suffixes, wordNum);
    for (int i = 0; i < chainSize; i++) {
    cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << endl;
    }

    string output = generateText(prefixes, suffixes, chainSize, order, wordNum);
    cout << output << endl;
    
    return 0;

}