#include <iostream>

using namespace std;

class Critter {
public:
    Critter(int hunger = 0, int boredom = 0);
    void talk();
    void eat(int food = 4);
    void play(int fun = 4);
    void checkStatus();

private:
    int m_hunger;
    int m_boredom;
    int getMood() const;
    void passTime(int time = 1);
};

Critter::Critter(int hunger, int boredom)
    : m_hunger(hunger)
    , m_boredom(boredom)
{
}
inline int Critter::getMood() const { return (m_hunger + m_boredom); }
void Critter::passTime(int time)
{
    m_hunger += time;
    m_boredom += time;
}
void Critter::talk()
{
    cout << "I'm a critter and I fell ";
    int mood = getMood();
    if (mood > 15) {
        cout << "mad.\n";
    } else if (mood > 10) {
        cout << "frustrated.\n";
    } else if (mood > 5) {
        cout << "okay.\n";
    } else {
        cout << "happy.\n";
    }
    passTime();
}
void Critter::eat(int food)
{
    cout << "Brrupp.\n";
    m_hunger -= food;
    if (m_hunger < 0) {
        m_hunger = 0;
    }
    passTime();
}
void Critter::play(int fun)
{
    cout << "Wheee!\n";
    m_boredom -= fun;
    if (m_boredom < 0) {
        m_boredom = 0;
    }
    passTime();
}
void Critter::checkStatus()
{
    cout << "hunger is " << m_hunger << ".\n";
    cout << "boredom is " << m_boredom << ".\n";
}
int main()
{
    Critter crit;
    crit.talk();

    int choice;
    do {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n";
        cout << "4 - Check critter status\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Good bye!\n";
            break;
        case 1:
            crit.talk();
            break;
        case 2:
            crit.eat();
            break;
        case 3:
            crit.play();
            break;
        case 4:
            crit.checkStatus();
            break;
        default:
            cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }

    } while (choice != 0);

    return 0;
}