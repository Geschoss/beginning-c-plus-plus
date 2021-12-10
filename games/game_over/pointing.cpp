#include <iostream>
#include <string>

using namespace std;

void print(int* pScore, int score);

int main()
{
    int score = 1000;
    int* pScore = &score;

    cout << "Assigning &score to pScore\n";
    print(pScore, score);

    cout << "\nAdding 500 to score\n";
    score += 500;
    print(pScore, score);

    cout << "\nAdding 500 to *pScore\n";
    *pScore += 500;
    print(pScore, score);

    cout << "Assigning &newScore to pScore\n";
    int newScore = 5000;
    pScore = &newScore;
    print(pScore, score);

    cout << "Assiging &str to pSttr\n";
    string str = "string";
    string* pStr = &str;
    cout << "str is: " << str << endl;
    cout << "*pStr is: " << *pStr << endl;
    cout << "(*pStr).size() is: " << (*pStr).size() << endl;
    cout << "pStr->size() is: " << pStr->size() << "\n";

    return 0;
}

void print(int* pScore, int score)
{
    cout << "&score is: " << &score << "\n";
    cout << "pScore is: " << pScore << "\n";
    cout << "score is: " << score << "\n";
    cout << "*pScore is: " << *pScore << "\n";
}