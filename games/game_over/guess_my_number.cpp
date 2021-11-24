#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int tries = 0;
    int guess;

    do {
        cout << "Enter a guess: ";
        cin >> guess;
        ++tries;
        if (guess > secretNumber) {
            cout << "Too hight!\n\n";
        } else if (guess < secretNumber) {
            cout << "Too low!\n\n";
        } else {
            cout << "\nThat's it! You got it in " << tries << " guesses!\n";
        }
    } while (guess != secretNumber);

    return 0;
}