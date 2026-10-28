#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

// Function prototypes
void displayMenu();
void createFile();
void readFile();
void appendToFile();
void searchText();
void deleteFile();

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(); // Clear the newline character from the buffer

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                appendToFile();
                break;
            case 4:
                searchText();
                break;
            case 5:
                deleteFile();
                break;
            case 0:
                cout << "Exiting File Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please select an option from the menu.\n";
        }
    } while (choice != 0);

    return 0;
}

// Function to display the program menu
void displayMenu() {
    cout << "\n===== FILE MANAGEMENT SYSTEM =====\n";
    cout << "1. Create a file and write content\n";
    cout << "2. Read a file\n";
    cout << "3. Append content to a file\n";
    cout << "4. Search text in a file\n";
    cout << "5. Delete a file\n";
    cout << "0. Exit\n";
}

// Module 1: Create a file and write content
void createFile() {
    string fileName, content;
    cout << "Enter file name (example: notes.txt): ";
    getline(cin, fileName);

    ofstream outFile(fileName); // Opens file for output (truncates by default)
    if (!outFile) {
        cout << "Error: Could not create the file.\n";
        return;
    }

    cout << "Enter content for the file: ";
    getline(cin, content);
    outFile << content << "\n";
    
    outFile.close();
    cout << "File created and content saved successfully.\n";
}

// Module 2: Read and display file content
void readFile() {
    string fileName, line;
    cout << "Enter file name to read: ";
    getline(cin, fileName);

    ifstream inFile(fileName); // Opens file for input
    if (!inFile) {
        cout << "Error: Could not open the file. Make sure the file exists.\n";
        return;
    }

    cout << "----- File Content -----\n";
    while (getline(inFile, line)) {
        cout << line << "\n";
    }
    cout << "------------------------\n";
    
    inFile.close();
}

// Module 3: Append new content to the end of an existing file
void appendToFile() {
    string fileName, content;
    cout << "Enter file name to append: ";
    getline(cin, fileName);

    // Opens file in append mode (ios::app)
    ofstream outFile(fileName, ios::app);
    if (!outFile) {
        cout << "Error: Could not open the file for appending.\n";
        return;
    }

    cout << "Enter content to append: ";
    getline(cin, content);
    outFile << content << "\n";

    outFile.close();
    cout << "Content appended successfully.\n";
}

// Module 4: Search for a word/phrase and report line numbers
void searchText() {
    string fileName, targetText, line;
    cout << "Enter file name to search: ";
    getline(cin, fileName);

    ifstream inFile(fileName);
    if (!inFile) {
        cout << "Error: Could not open the file for searching.\n";
        return;
    }

    cout << "Enter text to search for: ";
    getline(cin, targetText);

    int lineNumber = 0;
    bool found = false;

    while (getline(inFile, line)) {
        lineNumber++;
        // Case-sensitive exact matching utilizing string::find
        if (line.find(targetText) != string::npos) {
            cout << "Found on line " << lineNumber << ": " << line << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Text not found.\n";
    }

    inFile.close();
}

// Module 5: Delete a file from the directory
void deleteFile() {
    string fileName;
    cout << "Enter file name to delete: ";
    getline(cin, fileName);

    // Uses the standard C runtime utility remove()
    if (remove(fileName.c_str()) == 0) {
        cout << "File deleted successfully.\n";
    } else {
        cout << "Error: Could not delete the file. (Check permissions or if the file exists)\n";
    }
}
