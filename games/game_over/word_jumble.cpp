#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS]
        = { { "wall", "Do you fell you're banging you head agains something?" },
              { "glasses", "These might help you see the answer." },
              { "labored", "Going slowly. Is it?" },
              { "persistent", "Keep at it." },
              { "jumble", "It's what the game is all about" } };

    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];
    int score = theWord.size();

    string jumble = theWord;
    int length = jumble.size();
    for (int i = 0; i < length; ++i) {
        int index1 = (rand() % length);
        int index2 = (rand() % length);

        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    cout << "\t\t\tWelcom to Word Jumble!\n\n";
    cout << "Unscramble tthe letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The juble is: " << jumble;
    cout << "\nYou score: " << score << endl;
    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;

    while ((guess != theWord) && (guess != "quit")) {
        if (guess == "hint") {
            cout << theHint;
        } else {
            score = score - 1;
            cout << "Sorry. That's not it.";
            cout << "\nThe juble is: " << jumble;
            cout << "\nYou score: " << score << endl;
        }
        cout << "\n\nYour guess: ";
        cin >> guess;
    }
    if (guess == theWord) {
        cout << "\nThat's it! You guessed it!\n";
        cout << "You score: " << score << endl;
    }
    cout << "\nThanks for playing.\n";
    return 0;
}