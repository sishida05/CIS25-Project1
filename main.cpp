#include "markov.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

    // 
    string testWords[] = {"the", "cat", "sat", "down"};
    cout << joinWords(testWords, 0, 2) << endl;  // Should print: the cat
    cout << joinWords(testWords, 1, 3) << endl;  // Should print: cat sat down

    // // Creating a file for the text
    ofstream testFile("test.txt");
    testFile << "This is the test file that must contain words!" << endl;
    testFile << "This is another line of words that are in this file!" << endl;
    testFile.close();

    // Reading words from the file
    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    cout << "Read " << count << " words" << endl;
    for (int i = 0; i < 10 && i < count; i++) {
    cout << words[i] << endl;
    }

    // 
    string prefixes[10000], suffixes[10000];
    int chainSize = buildMarkovChain(words, count, 1, prefixes, suffixes, 10000);
    for (int i = 0; i < 20 && i < chainSize; i++) {
    cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << endl;
    }

    // 
    for (int i = 0; i < 10; i++) {
    cout << getRandomSuffix(prefixes, suffixes, chainSize, "the") << endl;
}


    return 0;
}