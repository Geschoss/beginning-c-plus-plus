#include <iostream>
using namespace std;

void changeScore(int& score);

int main()
{
    int score = 1000;
    int& scoreLink = score; // create link

    cout << "score is: " << score << endl;
    cout << "scoreLink is: " << scoreLink << "\n\n";

    cout << "Adding 500 to score\n";
    score += 500;
    cout << "score is: " << score << endl;
    cout << "scoreLink is: " << scoreLink << endl;

    cout << "Adding 500 to scoreLink\n";
    scoreLink += 500;
    cout << "score is: " << score << endl;
    cout << "scoreLink is: " << scoreLink << endl;

    cout << "Adding 1500 by changeScore()\n";
    changeScore(scoreLink);
    cout << "score is: " << score << endl;
    cout << "scoreLink is: " << scoreLink << endl;

    return 0;
}

void changeScore(int& score) { score += 1500; }