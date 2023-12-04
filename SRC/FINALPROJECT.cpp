// TEAM WAFFLES
// Xenon Garcia
// Daelon Ruidsel
// -------------------------------------
// Case 3: Vigenere Cipher Decryption
// Started: 11/25/2023
// Ended: 12/3/2023

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// Global
const string QUIT_1 = "Thank you for using this program!";
const string INVALID_ANSWER = "Please input a number!";

// Prototypes
int displayMenu(int&);
void titleScreen(int&);
void credits(int&);
void timesUsed_msg(int&);
bool isValid(int, int, int);
char returnToMenu(int&);
static void cinStuff();
bool lengthCheck(string, string);

// ENCRYPT & DECRYPT FUNCTIONS
string encryptVigenere(const string&, const string&);
string decryptVigenere(const string&, const string&);
string cipher(int, string, string);

int main() {
    // variables
    int timesUsed = 0;
    int userChoice;
    bool useAgain = false;
    char useCurrent;
    string plain, key, result;

    // LOOP
    while (useAgain == false) {
        // MENU DISPLAY
        system("cls");

        // For Testing
        /*cout << "plain: " << plain << endl;
        cout << "key: " << key << endl;
        cout << "result: " << result << endl;*/

        userChoice = displayMenu(timesUsed);

        // SWITCH CASE
        switch (userChoice) {
        case 1: // THIS CASE SHOULD ENCRYPT
            system("cls");
            timesUsed++;
            cinStuff();

            cout << "Vigenere Cipher Project - Encrypting Text" << endl;
            cout << "-------------------------------------------" << endl;

            // Text Input
            cout << "Input Text - Limit 50 Characters\nInput (No Spaces): ";
            getline(cin, plain);
            transform(plain.begin(), plain.end(), plain.begin(), ::toupper); // THIS CAPITALIZES THE LETTERS

            // Key Input
            cout << "\nKeyword - Limit 50 Characters\nInput (No Spaces): ";
            getline(cin, key);
            transform(key.begin(), key.end(), key.begin(), ::toupper); // THIS CAPITALIZES THE LETTERS

            // Length Checking Function
            if (lengthCheck(plain, key) == true) // If either are true, reset both plain & key inputs
            {
                plain = "";
                key = "";
                break;
            }

            // Result Output
            result = cipher(userChoice, plain, key);
            returnToMenu(timesUsed);
            break;
        case 2: // THIS CASE SHOULD DECRYPT
            system("cls");
            timesUsed++;
            cinStuff();

            // Setup a "do" loop for incorrect input until correct input
            do {
                // TITLE
                cout << "Vigenere Cipher Project - Decrypting Text" << endl;
                cout << "-------------------------------------------" << endl;

                // Ask user if want to use previous input
                cout << "Want to previous input? (Y/N)" << endl;
                cout << "User Choice: ";
                cin >> useCurrent;
                useCurrent = toupper(useCurrent);

                // If Yes
                if (useCurrent == 'Y') {
                    // If user decides to decrypt something
                    // without a previous input, tell user to
                    // encrypt something first and bring them
                    // back to the main menu
                    // otherwise continue
                    if (plain.empty() || key.empty()) {
                        cout << "\nNothing Exists!" << endl;
                        cout << "Please encrypt something first :)" << endl;
                    }
                    else {
                        cout << endl << "Using Previous Input!" << endl;
                        plain = result;
                    }
                }

                // If user doesn't want to use previous input
                if (useCurrent == 'N') {
                    cinStuff();

                    // Text Input
                    cout << "\nInput Text - Limit 50 Characters\nInput (No Spaces): ";
                    getline(cin, plain);
                    transform(plain.begin(), plain.end(), plain.begin(), ::toupper); // THIS CAPITALIZES THE LETTERS

                    // Key Input
                    cout << "\nKeyword - Limit 50 Characters\nInput (No Spaces): ";
                    getline(cin, key);
                    transform(key.begin(), key.end(), key.begin(), ::toupper); // THIS CAPITALIZES THE LETTERS

                    // Length Checking Function
                    if (lengthCheck(plain, key) == true) // If either are true, reset both plain & key inputs
                    {
                        plain = "";
                        key = "";
                        break;
                    }
                }

                // If it's not YES (y) or NO (n)
                if (useCurrent != 'Y' && useCurrent != 'N') {
                    system("cls");
                    cout << "Please make a proper choice." << endl;
                }
            } while (useCurrent != 'Y' && useCurrent != 'N');

            // Output
            if (!(plain.empty() || key.empty())) {
                result = cipher(userChoice, plain, key);
                cout << "Returning after this resets all inputs + result!" << endl;
                returnToMenu(timesUsed);

                // Reset Everything
                plain = "";
                key = "";
                result = "";
            }
            else
                returnToMenu(timesUsed);

            break;
        case 3: // THESE ARE THE CREDITS
            system("cls");
            credits(timesUsed);
            break;
        case 4: // PROGRAM QUIT
            system("cls");
            timesUsed_msg(timesUsed);
            cout << endl << QUIT_1 << endl;
            system("pause");
            exit(0);
        }
    }
}

//////////////////
// FUNCTIONS //
/////////////////

// Displays the Menu
int displayMenu(int& timesUsed) {
    int min = 1;
    int max = 4;
    int userChoice = 0;

    // Setup a "do" loop for incorrect input until correct input
    do {
        titleScreen(timesUsed);
        cout << "User Choice: ";

        // If the user input isn't a number
        while (!(cin >> userChoice)) {
            system("cls");
            titleScreen(timesUsed);
            cout << INVALID_ANSWER << endl;
            cinStuff();
            cout << "User Choice: ";
        }

        // If the option is not valid, user has to reinput their option
        if (!isValid(userChoice, min, max)) {
            system("cls");
            cout << "Please choose from the options below." << endl << endl;
        }
    } while (!isValid(userChoice, min, max));

    return userChoice;
}

// This sets up the Title Screen that is used for the DisplayMenu Function
void titleScreen(int& timesUsed) {
    cout << "       Vigenere Cipher - CIS7 Final" << endl;
    cout << "               Team WAFFLES" << endl;
    timesUsed_msg(timesUsed);
    cout << "1) Encrypt Text\n2) Decrypt Text\n3) Credits\n4) Quit Program" << endl;
}

// This Displays the Credits
void credits(int& timesUsed) {
    cout << " Vigenere Cipher Project Credits - Team WAFFLES" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "   Xenon Garcia | Interface & QoL Stuff" << endl;
    cout << " Daelon Ruidsel | Encrypt & Decrypt Functions" << endl;
    returnToMenu(timesUsed);
}

// This displays how many times a user has used this program
void timesUsed_msg(int& timesUsed) {
    if (timesUsed == 0) // Not yet used/just opened up the program
    {
        cout << "-------------------------------------------" << endl;
        cout << "You have not used this program at all yet." << endl;
        cout << "-------------------------------------------" << endl;
    }
    else if (timesUsed == 1) // Only used for proper grammer
    {
        cout << "-------------------------------------------" << endl;
        cout << "You have used this program " << timesUsed << " time." << endl;
        cout << "-------------------------------------------" << endl;
    }
    else // Used for anything after the first time
    {
        cout << "-------------------------------------------" << endl;
        cout << "You have used this program " << timesUsed << " times." << endl;
        cout << "-------------------------------------------" << endl;
    }
}

// Validation Test
bool isValid(int num, int min, int max) {
    if (num < min || num > max)
        return false;
    else
        return true;
}

// Return To Menu Function
char returnToMenu(int& timesUsed) {
    char userChoice;

    // Setup a "do" loop for incorrect input until correct input
    do {
        cout << endl;
        cout << "Want to go back to menu? (Y/N)" << endl;
        cout << "User Choice: ";
        cin >> userChoice;
        userChoice = toupper(userChoice);

        // If Yes
        if (userChoice == 'Y')
            cout << endl << "thumbs up emoji" << endl;

        // If No
        if (userChoice == 'N') {
            system("cls");
            timesUsed_msg(timesUsed);
            cout << endl << QUIT_1 << endl;
            system("pause");
            exit(0);
        }

        // If it's not YES (y) or NO (n)
        if (userChoice != 'Y' && userChoice != 'N') {
            system("cls");
            cout << "Please make a proper choice." << endl;
        }
    } while (userChoice != 'Y' && userChoice != 'N');

    return userChoice;
}

/////////////////////////////////
// ENCRYPT & DECRYPT FUNCTIONS //
/////////////////////////////////

// Encryption Function
string encryptVigenere(const string& plain, const string& key) {
    string ciphered;
    int keyLength = key.length();

    for (size_t i = 0; i < plain.length(); ++i) {
        char plainChar = plain[i];
        char keyChar = key[i % keyLength];
        char encryptedChar = (plainChar + keyChar) % 26 + 'A'; // Assuming uppercase letters

        ciphered += encryptedChar;
    }

    return ciphered;
}

// Decryption Function
string decryptVigenere(const string& ciphered, const string& key) {
    string decrypted;
    int keyLength = key.length();

    for (size_t i = 0; i < ciphered.length(); ++i) {
        char cipheredChar = ciphered[i];
        char keyChar = key[i % keyLength];
        char decryptedChar = (cipheredChar - keyChar + 26) % 26 + 'A'; // Assuming uppercase letters

        decrypted += decryptedChar;
    }

    return decrypted;
}

// DISPLAYS CIPHER + USES THE DECRYPT & ENCRYPT FUNCTION IN ONE FUNCTION
string cipher(int userChoice, string plain, string key) {
    // Variables
    string result;

    // Encryption or Decryption
    if (userChoice == 1) {
        cout << "\nENCRYPTING!!" << endl;
        // Call the function for encryption
        result = encryptVigenere(plain, key);
    }
    else if (userChoice == 2) {
        cout << "\nDECRYPTING!!" << endl;
        // Call the function for decryption
        result = decryptVigenere(plain, key);
    }

    // Output
    cout << "===========================================" << endl;
    cout << "Your plain text was: \"" << plain << "\"" << endl;
    cout << "Your keyword was: \"" << key << "\"" << endl;
    cout << "Your ciphered text: \"" << result << "\"" << endl; // Use 'result' here
    cout << "===========================================" << endl;
    return result;
}

////////////////
// misc funcs //
////////////////

// This checks the length of the string for input
bool lengthCheck(string plain, string key) {
    // Length Checking
    if (plain.length() > 50) {
        cout << "\nPlain Text Input exceeded 50 characters. Please try again." << endl;
        system("pause");
        return true;
    }
    else if (key.length() > 50) {
        cout << "\nKeyword Input exceeded 50 characters. Please try again." << endl;
        system("pause");
        return true;
    }
}

// Just to reduce like a couple of lines LOL
// This clears the cin input
// As well as ignoring any previous cin inputs
static void cinStuff() {
    cin.clear();
    cin.ignore();
}
