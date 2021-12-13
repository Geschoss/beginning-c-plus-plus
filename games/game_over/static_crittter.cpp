#include <iostream>

using namespace std;

class Critter {
public:
    static int s_total;
    static int getTotal();
    Critter(int hunger = 0);

private:
    int m_hunger;
};

int Critter::s_total = 0;
Critter::Critter(int hunger)
    : m_hunger(hunger)
{
    cout << "A critter has been born!" << endl;
    ++s_total;
}
int Critter::getTotal() { return s_total; };
int main()
{
    cout << "The total number of critters is: ";
    cout << Critter::s_total << "\n\n";
    Critter crit1, crit2, crit3;
    cout << "\nThe total numbeer of critters is: ";
    cout << Critter::getTotal();
    return 0;
}