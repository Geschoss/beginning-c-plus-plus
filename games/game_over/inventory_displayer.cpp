#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(const vector<string>& inventory);
void addInventory(vector<string> inventory);

int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    addInventory(inventory);
    display(inventory);

    return 0;
}

void display(const vector<string>& inventory)
{
    cout << "Your items:\n";
    vector<string>::const_iterator iter;
    for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
        cout << *iter << endl;
    }
}

void addInventory(vector<string> inventory)
{
    inventory.push_back("axe");

    cout << "Your new items:\n";
    vector<string>::const_iterator iter;
    for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
        cout << *iter << endl;
    }
}