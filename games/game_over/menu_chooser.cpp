#include <iostream>
using namespace std;

int main()
{
    cout << "Difficult Levels\n\n";
    cout << "1 - Easy" << endl;
    cout << "2 - Normal" << endl;
    cout << "3 - Hard" << endl;

    int choice;
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "You picked Easy.\n";
        break;
    case 2:
        cout << "You picked Normal.\n";
        break;
    case 3:
        cout << "You picked Hard.\n";
        break;
    default:
        cout << "You made an illegal choice.\n";
        break;
    }
    return 0;
}