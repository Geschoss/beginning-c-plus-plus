// Программа Game Stats 3.0
// Демонстрирует раоту с константами
#include <iostream>
using namespace std;

const int ALIEN_POINTS = 150;
enum difficult { NOVICE, EASY, NORMAL, HARD, UNBEATABLE };
enum shipCost { FIGHTER_COST = 25, BOMBER_COST, CRUISER_COST = 50 };

int main()
{
    int aliensKilled = 10;
    int score = aliensKilled * ALIEN_POINTS;
    cout << "score: " << score << endl;
    difficult userDifficalty = EASY;
    shipCost userShipCost = BOMBER_COST;

    cout << "\nTo upgrase my ship to a Cruiser will cost "
         << (CRUISER_COST - userShipCost) << " Resource Points. \n";
    return 0;
}