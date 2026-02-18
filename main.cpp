#include "markov.h"
#include <iostream>
using namespace std;

int main() {

    string testWords[] = {"the", "cat", "sat", "down"};
    cout << joinWords(testWords, 0, 2) << endl;  // Should print: the cat
    cout << joinWords(testWords, 1, 3) << endl;  // Should print: cat sat down

    ofstream testFile("test.txt");
    testFile.open();
    testFile << "This is a test file that must contain words!" << endl;
    testFile << "This is another line of words that are in this file!" << endl;

    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    cout << "Read " << count << " words" << endl;
    for (int i = 0; i < 10 && i < count; i++) {
    cout << words[i] << endl;
    }


    return 0;
}