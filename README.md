Date Published: 11/24/2023 <br />
Last Updated: 12/5/2023 - 8:36 PM
# Case 3: Vigenere Cipher Decryption
Vigenere Cipher is a method of encrypting alphabetic text. It uses a simple form of polyalphabetic
substitution. A polyalphabetic cipher is any cipher based on substitution, using multiple substitution
alphabets .The encryption of the original text is done using the Vigenère square or Vigenère table.
The table consists of the alphabets written out 26 times in different rows, each alphabet shifted
cyclically to the left compared to the previous alphabet, corresponding to the 26 possible Caesar
Ciphers. <br />
At different points in the encryption process, the cipher uses a different alphabet from one of the rows. <br />
The alphabet used at each point depends on a repeating keyword. <br />
For generating key, the given keyword is repeated in a circular manner until it matches the length of the
plain text.

## Tasks
1. Given the above description of the Vigenère cipher, create a C++ program that encrypt and
decrypts a message from the user.
2. Test the program to verify that the output is accurate. Assess program limitations.
3. Provide documentation that entails programming approach for encryption and decryption.

## Team WAFFLES
### Team Members:
- Xenon Garcia
- Daelon Ruidsel

## Programming Approaches
# Vigenere Cipher Project

## Introduction
This project implements a Vigenere Cipher for text encryption and decryption. The program is developed in C++ and provides a user-friendly console interface.

## Programming Approach
The project follows a modular and structured approach, utilizing functions for different aspects of the program. Decision-making is handled through switch-case statements, ensuring a clear control flow. The code aims for readability and maintainability through consistent naming conventions and comments.

## Project Structure
The project is organized into several key components:

- **Main Program:** The main program controls the flow of the application, handling user input and invoking relevant functions.
- **Functions:** Different functionalities, such as menu display, encryption, decryption, and user interaction, are encapsulated into separate functions.
- **Global Constants and Variables:** Constants and variables are declared globally for easy access and modification.

## Functions

### `displayMenu()`
This function displays the main menu, prompting the user to make a selection. It ensures valid input and returns the user's choice.

### `titleScreen()`
Displays the title screen, including project information and usage statistics.

### `credits()`
Outputs the credits section, acknowledging the contributions of team members.

### `timesUsedMsg()`
Outputs a message indicating how many times the program has been used.

...

## Limitations

- **Input Length:** The program currently limits input text and keywords to 50 characters. Consider enhancing this to handle longer inputs.

## Recommendations for Improvement

- **Dynamic Input Handling:** Allow for dynamic input lengths instead of fixed limits, providing a more flexible user experience.
- **Error Handling:** Implement more detailed error messages and instructions for users when input limits are exceeded or incorrect choices are made.

## Usage

To run the program, follow these steps:

1. Clone the repository.
2. Compile the C++ code using [compiler_name].
3. Execute the compiled program.

## How To Use
After running the program, you're greeted with 4 options (in order): Encrypt, Decrypt, Credits, and Quit. <br />

If you would like to encrypt, type 1 then press enter: <br />
1) Type in what word you would like to encrypt (no spaces)
2) Type in the keyword (Also no spaces)
3) Output displays in the following order: Plain Text, Keyword, Ciphered Text.

If you would like to decrypt, type 2 then press enter: <br />
1) Text appears "Would you like to use previous input? (y/n)"
   - (If Y) If you haven't already encrypted something, it'll ask you to encrypt something first.
      - (If Y) If you have encrypted something already, it'll use your previous input.
   - (If N) If you don't want to use previous input, it'll ask you to input something.
      - Steps are like encrypting so no need to repeat.
2) Once decryption is done, once prompted to exit, everything will reset.

If you want to see the credits, type 3 then press enter. <br />
If you would like to stop using the program, type 4 then press enter. <br />

**In all instances, it would ask you if you would like to return to the menu,**
   - If yes, you'll return to the menu
   - If no, program will end
