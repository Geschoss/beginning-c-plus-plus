#include <iostream>
using namespace std;

int main()
{
    char again = 'y';
    while (again == 'y') {
        cout << "\n**Play an exciting game**";
        cout << "\nDo you want to play again? (y/n): ";
        cin >> again;
    }

    again = 'n';

    do {
        cout << "\nNo mb you want to play again!";
        cout << "\nDo you want to play again? (y/n): ";
        cin >> again;
    } while (again == 'y');

    return 0;
}