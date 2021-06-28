#include <iostream>

using namespace std;
enum shipCost
{
    FIGHTER_COST = 25,
    BOMBER_COST,
    CRUISER_COST = 50,
};
enum difficulty
{
    NOVICE,
    EASY,
    NORMAL,
    HARD,
    UNBEATABLE,
};
const int ALIEN_POINTS = 150;

int main()
{

    int aliensKilled = 10;
    int score = aliensKilled * ALIEN_POINTS;

    cout << "score: " << score << endl;

    difficulty myDifficulte = EASY;

    shipCost myShipCost = BOMBER_COST;
    cout << "\nTo update my ship to Cruiser will cost "
         << (CRUISER_COST - myShipCost)
         << " Resource Points. \n";

    return 0;
}