
// Meghan Bibb
// 08/01/2018
// This file utilizes the MyVector object to allow a user
//      to play as the guesser or asked individual in a game of hang man
//      The outline/ flowchart of this program is located
//           at the bottom of this file

#include <iostream>
#include <fstream>
#include <vector>
#include "MyVector.h"

using namespace std;

int main() {
    int numGuesses = 7;
    string word;
    vector<string> storage;
    ifstream input;
    input.open("alphabet.txt");
    if(!input.is_open()){
        cout << "file not open" << endl;
        return 0;
    } else {

        //fills vector
    }




    return 0;
}




/*
 *  Draft of expectations / flow of the hangman program
 *
 * - two options:
 *      - as the user: guess or give a word to be guessed? (Q1)
 *
 * - guess:
 *      - create the int guesses initialized with 7
 *      - randomly select a word and store it in the string word.
 *      - shows '_' * the ammount of characters in word.
 *      - displays a text-image of a hangman to the screen
 *      - asks if the user wants to guess a letter or word (Q2)
 *      - if user guesses a word...
 *          - strcmp, display y/n
 *              - if no then decrement guesses and return to Q2
 *              - if yes then display "you win!" message
 *              - ask if they would like to play again (Q3)
 *                  -if no, end the program
 *      - if user guesses a letter
 *          - scan word for the letter
 *          - if found reprint the '_' string revealing the given letters
 *              - if no '_'s remain and guesses >= 0, display "you win"
 *          - if not found decrement guesses by 1
 *               - if guesses > 0, repeat the loop
 *
 */