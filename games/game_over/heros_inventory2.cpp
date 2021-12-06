#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    cout << "You have " << inventory.size() << " ittems.\n";
    cout << "\nYour items:\n";
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        cout << inventory[i] << endl;
    }
    cout << "\nYou trade your sword for a battle axe.";
    inventory[0] = "battle axe";
    cout << "\nYou items:\n";
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        cout << inventory[i] << endl;
    }
    cout << "\nThe item name: '" << inventory[0] << "' has ";
    cout << inventory[0].size() << " lettters in it.\n";
    cout << "\nYour shield is destroyed in a fierce battle.";
    inventory.pop_back();
    cout << "\nYou were robbed of all of your possessions by a thif.";
    inventory.clear();
    if (inventory.empty()) {
        cout << "\nYou have nothing.\n";
    } else {
        cout << "\nYou have at least one item.\n"; 
    }

    return 0;
}