#include <iostream>

using namespace std;

class Critter {
public:
    int hunger;
    void greet();
    void hi();
};

void Critter::greet()
{
    cout << "Hi, I'm a critter. My hunger lavel is " << hunger << ".\n";
}

void Critter::hi() { cout << "Hi! My name is critter" << "!\n"; }

int main()
{
    Critter crit1;
    Critter crit2;

    crit1.hunger = 9;
    cout << "crit1's hunger level is " << crit1.hunger << ".\n";

    crit2.hunger = 3;
    cout << "crit1's hunger level is " << crit2.hunger << ".\n";

    crit1.greet();
    crit2.greet();

    return 0;
}