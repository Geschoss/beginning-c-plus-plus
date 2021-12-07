#include <iostream>
using namespace std;

int radiation(int healtth);

int main()
{
    int health = 80;
    cout << "Your health is " << health << "\n\n";

    health = radiation(health);
    cout << "After radiation exposure your healt is " << health << "\n\n";
    health = radiation(health);
    cout << "After radiation exposure your healt is " << health << "\n\n";
    health = radiation(health);
    cout << "After radiation exposure your healt is " << health << "\n\n";

    return 0;
}

inline int radiation(int health) { return (health / 2); }