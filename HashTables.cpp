#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Create an unordered_map (hash table) to store phone numbers
    unordered_map<string, string> phoneBook;

    // Insert key-value pairs (Name -> Phone Number)
    phoneBook["John"] = "555-1234";
    phoneBook["Alice"] = "555-5678";
    phoneBook["Bob"] = "555-8765";

    // Lookup phone numbers by name
    string name = "Alice";
    if (phoneBook.find(name) != phoneBook.end()) {
        cout << name << "'s phone number is " << phoneBook[name] << endl;
    } else {
        std::cout << name << " is not in the phone book." << endl;
    }

    // Remove a contact from the phone book
    phoneBook.erase("John");

    // Print all contacts in the phone book
    cout << "\nPhone Book:" << endl;
    for (const auto& entry : phoneBook) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
