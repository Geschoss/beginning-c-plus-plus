#include <iostream>
using namespace std;

int main()
{
    int score;
    cout << "Enter your score: ";
    cin >> score;

    if (score >= 1000) {
        cout << "Your scored 1000 or more. Impressice!\n";
    } else if (score >= 500) {
        cout << "Your scored 500 or more. Nice!\n";
    } else if (score >= 250) {
        cout << "Your scored 250 or more. Decent.\n";
    } else {
        cout << "Your scored less than 250. Nothing to drag about.\n";
    }

    return 0;
}