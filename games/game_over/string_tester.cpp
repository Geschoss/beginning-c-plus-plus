#include <iostream>
#include <string>
using namespace std;

int main()
{
    string world1 = "Game";
    string world2("Over");
    string world3(3, '!');
    string phrase = world1 + " " + world2 + " " + world3;

    cout << "The phrase is: " << phrase << "\n\n";
    cout << "The phrase has: " << phrase.size() << " characters in it.\n\n";
    cout << "The character at position 0 is: " << phrase[0] << "\n\n";
    cout << "Changing the character at position 0.\n";

    phrase[0] = 'L';

    cout << "The phrase is now: " << phrase << "\n\n";

    for (unsigned int i = 0; i < phrase.size(); ++i) {
        cout << "Charactre at position " << i << " is: " << phrase[i] << endl;
    }

    cout << "\nThe sequence 'Over' begins at location ";
    cout << phrase.find("Over") << endl;
    if (phrase.find("eggplant") == string::npos) {
        cout << "'eggplant' is not in the phrase.\n\n";
    }

    phrase.erase(4, 5);
    cout << "The phrase is now: " << phrase << endl;
    phrase.erase(4);
    cout << "The phrase is now: " << phrase << endl;
    phrase.erase();
    cout << "The phrase is now: " << phrase << endl;

    if (phrase.empty()) {
        cout << "\nThe phrase is no more.\n";
    }

    return 0;
}