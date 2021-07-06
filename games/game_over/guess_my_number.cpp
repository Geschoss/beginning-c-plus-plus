#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber, min = 1, max = 100;
    int tries = 0;
    bool exit = false;
    int guess;
    char answer;
    cout << "\tWelcom to Guess My Number\n\n";
    cout << "Enter you secret number beetwen 1 and 100!\n";

    cin >> secretNumber;

    do
    {
        cout << "Hm! trying guess: \n";
        int range = max - min + 1;
        guess = rand() % range + min;
        
        ++tries;

        cout << "It's " << guess << "?\n";

        cout << "If it too high, press h\n";
        cout << "If it too low, press l\n";
        cin >> answer;

        if (answer == 'h')
        {
            cout << "Hm, ok, let's try arain";
            max = guess - 1;
        }
        else if (answer == 'l')
        {
            min = guess + 1;
        }
        else
        {
            cout << "\nThat's it! You got it in " << tries << " guesses!\n";
        }
    } while (guess != secretNumber);

    return 0;
}