#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using namespace std;

int main()
{
    char cmd = ' ';
    string gameTitle = "";
    vector<string> games;
    vector<string>::const_iterator gameIter;

    cout << "\nWellcome to your game list!\n\n";

    while (true) {

        cout << "This is your games: \n";
        if (games.empty()) {
            cout << "You don't have games yet!=(\n";
        } else {
            for (gameIter = games.begin(); gameIter != games.end();
                 ++gameIter) {
                cout << *gameIter << endl;
            }
        }

        cout << "\nCommand: q - quet, a - add.\n";
        cout << "Enter command: ";
        cin >> cmd;

        if (cmd == 'q') {
            break;
        }

        if (cmd == 'a') {
            cout << "\nEnter game title: ";
            cin >> gameTitle;
            games.push_back(gameTitle);
        }
    }
    return 0;
}