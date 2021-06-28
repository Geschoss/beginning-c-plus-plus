#include <iostream>
using namespace std;

int main() {
    int score;
    double distance;
    char palayAgain;
    bool shieldsUp;
    short lives, aliensKilled;
    
    score = 0; 
    distance = 1200.76;
    palayAgain = 'y';
    shieldsUp = true;
    lives = 3;
    aliensKilled = 10;

    cout << "\nscore: " << score << endl;
    cout << "lives: " << lives << endl;
    cout << "palyAgain: " << palayAgain << endl;
    cout << "distance: " << distance << endl;
    
    return 0;
}