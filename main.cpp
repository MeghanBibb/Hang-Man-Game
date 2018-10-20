// Meghan Bibb
// 10/20/2018
// This file utilizes a hashTable to allow a user
//      to play as the guesser or asked individual in a game of hang man

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


#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <unordered_map>
#include <cctype>

const int LETTERS_IN_ALPHABET = 26;

using namespace std;

int hashKey(string word, int numItems);
void display(int numGuesses, string word, bool letters[],bool isIn[], ostream &os = cout);

int main() {
    int numGuesses = 5;
    ifstream input;
    string word;
    int key, numItems = 0, randIndex = 0, wordSize = 0;
    unordered_map<int,string> dictionary;
    pair<int,string> myPair;
    bool guessedLetters[LETTERS_IN_ALPHABET];
    bool found = false;

    //input file
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

    randIndex = rand() % numItems;
    word = dictionary.at(randIndex);
    wordSize = word.size();   //keep this, its efficient in limiting function calls
    bool *foundNdx = new bool[wordSize];

    //makes all letters lowercase
    for(short i = 0; i < wordSize; i++){
        word[i] = tolower(word[i]);
    }

    //default state of guessedLetters is false
    for(int i = 0; i < LETTERS_IN_ALPHABET; i++){
        guessedLetters[i] = false;
    }

    //default state of foundNdx is false
    for(int i = 0; i < wordSize; i++){
        foundNdx[i] = false;
    }

    //user guesses a word
    if(letter == 'g'){
        do{
            cout << "Enter a letter" << endl;
            cin >> letter;
            letter = tolower(letter);

            //determines whether letter is in the word
            for(unsigned int i = 0; i < wordSize; i++){
                if(word.at(i) == letter){
                    reveal = true;
                    foundNdx[i] = true;
                }
            }
            guessedLetters[letter-'a'] = true;

            //if letter is in the word, determine if word has been guessed
            //if letter is not in the word, decrement guesses
            if(!reveal){
                numGuesses--;
            }else {
                found = true;
                for(int i = 0; i < wordSize && found; i++){
                    if(!foundNdx[i]){
                        found = false;
                    }
                }
                reveal = false;
            }

            display(numGuesses, word, guessedLetters, foundNdx);

        }while(numGuesses > 0 && !found);

        if(found){
            cout << "\nYou found the word '" << word << "'!" << endl;
        } else {
            cout << "\nYou FAILED to guess the word '" << word << "'!" << endl;
        }
    }

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

void display(int numGuesses, string word, bool letters[], bool isIn[], ostream &os){
    char c;
    //prints letters in word guessed so far
    for(int i = 0; i < word.size(); i++){
        if(isIn[i]){
            os << word.at(i) << " ";
        }else {
            os << "_ ";
        }
    }

    cout << "\nLetters Guessed: " << endl;
    for(int i = 0; i < LETTERS_IN_ALPHABET; i++){
        if(letters[i]){
            c = 'a' + i;
            os << c << " ";
        }
    }

    cout << "\nGuesses Remaining: " << numGuesses << endl;
}
