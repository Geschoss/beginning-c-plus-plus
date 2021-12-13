#include <iostream>

using namespace std;

class Critter {
public:
    Critter(int hunger = 0);
    int getHunger() const;
    void setHunger(int hunger);

private:
    int m_hunger;
};

Critter::Critter(int hunger)
    : m_hunger(hunger)
{
    cout << "A new critter has been born!" << endl;
}
int Critter::getHunger() const { return m_hunger; }
void Critter::setHunger(int hunger)
{
    if (hunger < 0) {
        cout << "You can't set a critter's hunger to a negative number.\n\n";
    } else {
        m_hunger = hunger;
    }
}

int main()
{
    Critter crit(5);
    // cout << crit.m_hunger;
    cout << "Calling getHunger(): " << crit.getHunger() << "\n\n";
    cout << "Calling setHunger() with -1\n";
    crit.setHunger(-1);

    cout << "Calling setHunger() with 9.\n";
    crit.setHunger(9);

    cout << "Calling getHunger(): " << crit.getHunger() << "\n\n";

    return 0;
}