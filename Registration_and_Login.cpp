#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "Register\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app); // Append to the file
    if (file.is_open()) {
        file << username << " " << password << endl;
        cout << "Registration successful!\n";
        file.close();
    } else {
        cout << "Error opening file for writing.\n";
    }
}

// Function to login
void loginUser() {
    string username, password, fileUser, filePass;
    bool found = false;

    cout << "Login\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    if (file.is_open()) {
        while (file >> fileUser >> filePass) {
            if (fileUser == username && filePass == password) {
                found = true;
                break;
            }
        }
        file.close();

        if (found) {
            cout << "Login successful!\n";
        } else {
            cout << "Invalid username or password.\n";
        }
    } else {
        cout << "Error opening file for reading.\n";
    }
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
