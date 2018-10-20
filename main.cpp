
// Meghan Bibb
// 08/01/2018
// This file utilizes the MyVector object to allow a user
//      to play as the guesser or asked individual in a game of hang man
//      The outline/ flowchart of this program is located
//           at the bottom of this file

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "MyVector.h"

using namespace std;

int hashKey(string word, int numItems);

int main() {
    int numGuesses = 4;
    ifstream input;
    string word;
    int key, numItems = 0, randIndex = 0;
    unordered_map<int,string> dictionary;
    pair<int,string> myPair;

    input.open("alphabet.txt");
    if(!input.is_open()){
        cout << "file not open" << endl;
        return 0;
    }

    //fills map
    do{
        input >> word;
        numItems++;
        key = hashKey(word, numItems);
        myPair.first = key;
        myPair.second = word;
        dictionary.insert(myPair);
    }while(!input.eof());

    randIndex = rand() % numItems;
    word = dictionary.at(randIndex);

    char letter;
    bool valid = false, reveal = false;
    do{
        cout << "If you would like to guess a word input 'g': " << endl;
        cout << "If you would like to have your word guessed insert 'w' : " << endl;
        cin >> letter;
        if(letter == 'G' || letter == 'W'){
            //32 is the difference in ASCII values between upper and lower case
            letter += 32;
        }
        if(letter == 'g' || letter == 'w'){
            valid = true;
        }
    }while(!valid);

    bool *foundNdx = new bool[word.size()];
    bool found = false;
    int wordSize = word.size();
    for(int i = 0; i < wordSize; i++){
        foundNdx[i] = false;
    }

    if(letter == 'g')
    do{
        cout << "Enter a letter" << endl;
        cin >> letter;
        for(unsigned int i = 0; i < wordSize; i++){
            if(word.at(i) == letter){
                reveal = true;
                foundNdx[i] = true;
            }
        }
        if(!reveal){
            numGuesses--;
        }else {
            found = true;
            for(int i = 0; i < wordSize && found; i++){
                if(word.at(i) != true){
                    found = false;
                }
            }
        }
    }while(numGuesses > 0 || !found);

    /*
    (*it).first;             // the key value (of type Key)
    (*it).second;            // the mapped value (of type T)
    (*it);                   // the "element value" (of type pair<const Key,T>)
    ifstream input;
    */



    return 0;
}

int hashKey(string word, int numItems){
    int num = 0;
    for(int i = 0; i < word.size(); i++){
        num += word.at(i)*3;
    }
    num = num % numItems;
    return num;
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