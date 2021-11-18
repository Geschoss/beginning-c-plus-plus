#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

const int GOLD_PIECES = 900;

int main()
{
    int adventurers, killed, survivors;
    string leader;
    // get user info
    cout << "\n";
    cout << "Welcom to Lost Fortune\n\n";
    cout << "Please enter the following for your personalized adventure\n";
    cout << "Enter a number: ";
    cin >> adventurers;
    cout << "Enter a number, smaller than the first: ";
    cin >> killed;
    survivors = adventurers - killed;
    cout << "Enter your last name: ";
    cin >> leader;

    return 0;
}