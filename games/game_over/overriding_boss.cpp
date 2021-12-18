#include <iostream>

using namespace std;

// Enemy
class Enemy {
public:
    Enemy(int damage = 10);
    virtual void taunt() const;
    virtual void attack() const;

private:
    int m_damage;
};
Enemy::Enemy(int damage)
    : m_damage(damage) {};
void Enemy::taunt() const { cout << "The enemy says will fight you.\n"; }
void Enemy::attack() const
{
    cout << "Attack! Inflicts " << m_damage << " damage points.";
}
// Boss
class Boss : public Enemy {
public:
    Boss(int damage = 30);
    virtual void taunt() const;
    virtual void attack() const;
};

Boss::Boss(int damage)
    : Enemy(damage)
{
}
void Boss::taunt() const
{
    cout << "The boss says he will end your piriful existence.\n";
}
void Boss::attack() const
{
    Enemy::attack();
    cout << " and laughs heartily at you.\n";
}

int main()
{
    cout << "Enemy object:\n";
    Enemy enemy;
    enemy.taunt();
    enemy.attack();

    cout << "\n\nBoss object:\n";
    Boss boss;
    boss.taunt();
    boss.attack();

    return 0;
}