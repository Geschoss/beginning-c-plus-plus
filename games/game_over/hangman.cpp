#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

const int MAX_WRONG = 8;

int main()
{
    vector<string> words;
    words.push_back("dog");
    words.push_back("cat");
    words.push_back("mouse");
    words.push_back("house");

    shuffle(words.begin(), words.end(),
        default_random_engine(static_cast<unsigned int>(time(0))));

    string word = words[0];
    cout << word << endl;

    cout << "Welcom tto Hangman. Good luck!";

    int attempt = 0;
    char guess;
    string used = "";
    string soFar(word.size(), '-');

    while (attempt < MAX_WRONG && soFar != word) {
        cout << "\nYou have " << MAX_WRONG - attempt
             << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the worf is:\n" << soFar << endl;

        cout << "\n\nEnter your guess: ";
        cin >> guess;

        while(used.find(guess) != string::npos)
        {
            cout << "\nYou've alreasy guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
        }
       
        used += guess;


        if (word.find(guess) != string::npos) {
            cout << "That's right! " << guess << " is in the word.\n";
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] == guess) {
                    soFar[i] = guess;
                }
            }
        } else {
            cout << "Sorry. " << guess << " isn't in the word.\n";
            ++attempt;
        }
    }

    if (soFar == word) {
        cout << "\n\nYeee! You got it! Word is: " << word << endl;
    }

    return 0;
}