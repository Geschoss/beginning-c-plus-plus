#include <iostream>

using namespace std;

class Enemy {

public:
    Enemy();
    void attack() const;

protected:
    int m_damage;
};
Enemy::Enemy()
    : m_damage(10)
{
}
void Enemy::attack() const
{
    cout << "Attack inflicts " << m_damage << " damage points!\n";
}
class Boss : public Enemy {
public:
    Boss();
    void specialAttack() const;

private:
    int m_damageMultiplier;
};
Boss::Boss()
    : m_damageMultiplier(3)
{
}
void Boss::specialAttack() const
{
    cout << "Special attack inflicts " << (m_damageMultiplier * m_damage);
    cout << " damage points!\n";
}

int main()
{
    cout << "Creating an enemy.\n";
    Enemy enemy1;
    enemy1.attack();

    cout << "\nCreating a boss\n";
    Boss boss;
    boss.attack();
    boss.specialAttack();

    return 0;
}