#include <iostream>

using namespace std;

class Critter {
public:
    Critter(int hunger = 0);
    int hunger;
    void greet();
};

Critter::Critter(int hunger)
    : hunger(hunger)
{
    cout << "A new critter has been born!" << endl;
}
void Critter::greet()
{
    cout << "Hi, I'm a critter. My hunger level is " << hunger << ".\n\n";
}

int main()
{
    Critter crit(7);
    crit.greet();

    return 0;
}