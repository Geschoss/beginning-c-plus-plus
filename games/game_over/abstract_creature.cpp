#include <iostream>

using std::cout, std::endl;

class Creature {
public:
    Creature(int health = 100);

    virtual void greet() const = 0;
    virtual void displayHealth() const = 0;

protected:
    int m_Health;
};
Creature::Creature(int health)
    : m_Health(health)
{
}

class Orc : public Creature {
public:
    Orc(int health = 120);
    virtual void greet() const;
    virtual void displayHealth() const;
};
Orc::Orc(int health)
    : Creature(health)
{
}
void Orc::greet() const { cout << "The orc grunts hello.\n"; }
void Orc::displayHealth() const { cout << "Health: " << m_Health << endl; }

int main()
{
    Creature* pCreature = new Orc();
    pCreature->greet();
    pCreature->displayHealth();
    return 0;
}