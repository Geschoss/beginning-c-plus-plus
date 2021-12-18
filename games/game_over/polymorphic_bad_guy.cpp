#include <iostream>

using std::cout;

class Enemy {
public:
    Enemy(int damage = 10);
    virtual ~Enemy();
    virtual void attack() const;

protected:
    int* m_pDamage;
};
Enemy::Enemy(int damage) { m_pDamage = new int(damage); }
Enemy::~Enemy()
{
    cout << "In Enemy destructor, daleting m_pDamage.\n";
    delete m_pDamage;
    m_pDamage = 0;
}
void Enemy::attack() const
{
    cout << "An enemy attack and inflicts " << *m_pDamage << " damage points.";
}

class Boss : public Enemy {
public:
    Boss(int multiplier = 3);
    virtual ~Boss();
    virtual void attack() const;

protected:
    int* m_pMultiplier;
};
Boss::Boss(int multiplier) { m_pMultiplier = new int(multiplier); }
Boss::~Boss()
{
    cout << "In Boss destructor. Deleting m_pMultiplier.\n";
    delete m_pMultiplier;
    m_pMultiplier = 0;
}
void Boss::attack() const
{
    cout << "A boss attack and inflicts " << (*m_pDamage) * (*m_pMultiplier)
         << " damage points.";
}
int main()
{
    cout << "Calling attack() on Boss object through pointer to Enemy:\n";
    Enemy* pBadGuy = new Boss();
    pBadGuy->attack();

    cout << "\n\nDeleting pointer to Enemy:\n";
    delete pBadGuy;
    pBadGuy = 0;
    return 0;
}