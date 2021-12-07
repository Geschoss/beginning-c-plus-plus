#include <iostream>
#include <string>
using namespace std;

char askYesNo1();
char askYesNo2(string question);

int main()
{
    char answer1 = askYesNo1();
    cout << "Thanks for answering: " << answer1 << "\n\n";

    char answer2 = askYesNo2("Do you widh to save your game?");
    cout << "Thanks for answering: " << answer2 << "\n";

    return 0;
}

char askYesNo1()
{
    char response;
    do {
        cout << "Please enter 'y' or 'n': ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}
char askYesNo2(string question)
{
    char response;
    do {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}