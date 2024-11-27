#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    int repeatedCount = 0;
    int length = word.length();

    for (int i = 0; i < length; i++) 
    {
        char target = word[i]; 
        int count = 0;
        
        if (target >= 'a' && target <= 'z') {
            for (int j = 0; j < length; j++)
            {
                char current = word[j];
                if (current == target) 
                {
                    count++;
                }
            }
            if (count > 1) {
                repeatedCount++;
                for (int j = 0; j < length; j++) {
                    char& current = word[j];
                    if (current == target) {
                        current = '0'; 
                    }
                }
            }
        }
    }

    cout << "Number of repeated letters: " << repeatedCount << endl;

    return 0;
}
