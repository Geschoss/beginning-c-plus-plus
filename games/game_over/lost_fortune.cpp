#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// constants
const int GOLD_PIECES = 900;

int main()
{
    int adventures, killed, survivors;
    string leader;
    // get info from user
    cout << "Welcom to Lost Fortune\n\n";
    cout << "Please enter the following for your personalized adventure\n";
    cout << "Enter a number: ";
    cin >> adventures;
    cout << "Enter a number, smaler then the first: ";
    cin >> killed;
    survivors = adventures - killed;
    cout << "Enter you last name: ";
    cin >> leader;

    // story
    cout << "\nA brave group of " << adventures << " set out on a quest";
    cout << "-- in search of the treasure of the Ancient Dwatves";
    cout << "The group was led by that legendary rogue." << leader << "\n";
    cout << "\nAloang the way a band of marauding ogres ambushed the party. ";
    cout << "All fought bravely under the command of " << leader;
    cout << " and the ogres were defeated but at a cost. ";
    cout << "Of the adventurers. " << killed << " were vanquished. ";
    cout << "leaving just " << survivors << " in the group.\n";
    cout << "Bla bla bla\n";

    cout << leader << " held on to the extra " << (GOLD_PIECES % survivors);

    return 0;
}