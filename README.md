Date Published: 11/24/2023 <br />
Last Updated: 12/5/2023 - 5:56 AM
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
how we approached this program should go here

## How To Use
1) After running the program, you're greeted with 4 options (in order): Encrypt, Decrypt, Credits, and Quit
2) If you would like to encrypt, type 1 then press enter:
   1) Type in what word you would like to encrypt (no spaces)
   2) Type in the keyword (Also no spaces)
   3) Output displays in the following order: Plain Text, Keyword, Ciphered Text
3) If you would like to decrypt, type 2 then press enter:
   1) Text appears "Would you like to use previous input?"
      - If you haven't already encrypted something, it'll ask you to encrypt something first
      - If you don't want to use previous input, it'll ask you to input something
         - Steps are like encrypting so no need to repeat
   2) If you have encrypted something already, it'll use your previous input
4) If you want to see the credits, type 3 then press enter
5) If you would like to stop using the program, type 4 then press enter

**In all instances, it would ask you if you would like to return to the menu,**
- If yes, you'll return to the menu
- If no, program will end
