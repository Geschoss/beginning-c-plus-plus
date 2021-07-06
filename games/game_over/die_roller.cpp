#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    char again = 'y';

    srand(static_cast<unsigned int>(time(0)));
    // run generator random numbers

    while (again == 'y')
    {
        int randomNumber = rand();
        int die = (randomNumber % 8) + 1;
        cout << "You rolled a " << die << endl;
        cout << "Again? (y\\n) \n";
        cin >> again;
    }
    return 0;
}