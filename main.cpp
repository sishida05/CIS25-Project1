#include "markov.h"
#include <iostream>
using namespace std;

int main() {

    string testWords[] = {"the", "cat", "sat", "down"};
    cout << joinWords(testWords, 0, 2) << endl;  // Should print: the cat
    cout << joinWords(testWords, 1, 3) << endl;  // Should print: cat sat down


    return 0;
}