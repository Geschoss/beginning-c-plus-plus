#include <iostream>
#include <string>
#include <vector>

using namespace std;

string& refToElement(vector<string>& inventory, int i);

int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("aromor");
    inventory.push_back("shield");

    cout << "Sending the returned reference to cout:\n";
    cout << refToElement(inventory, 1) << endl;

    cout << "Assigning the returned reference to another reference.\n";
    string& rStr = refToElement(inventory, 2);

    cout << "Sending the new reference to cout:\n";
    cout << rStr << "\n\n";

    cout << "Assingning the returned reference to a string object.\n";
    string str = refToElement(inventory, 0);
    cout << str << "\n\n";

    cout << "Altering an object through a returned reference.\n";
    rStr = "Healing Potion";

    cout << "Sending the altered object to cout:\n";
    cout << inventory[2];

    return 0;
}

string& refToElement(vector<string>& vec, int i) { return vec[i]; }
