#include <iostream>

using namespace std;

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    int frequency[26] = {0};

    for (int i = 0; i < word.length(); i++) {
        char character = word[i];
        if (character >= 'a' && character <= 'z') { 
            frequency[character - 'a']++;
        }
    }

    int repeatedCount = 0;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 1) {
            repeatedCount++;
        }
    }

    cout << "Number of repeated letters: " << repeatedCount << endl;

    return 0;
}
