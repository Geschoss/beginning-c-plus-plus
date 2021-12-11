#include <iostream>

using namespace std;

void badSwap(int x, int y);
void goodSwap(int* const pX, int* const pY);

int main()
{
    int myScore = 150;
    int yourScore = 1000;

    cout << "Original values\n";
    cout << "myScore: " << myScore << "\n";
    cout << "yourScore: " << yourScore << "\n\n";

    cout << "Calling badSwap()\n";
    badSwap(myScore, yourScore);

    cout << "myScore: " << myScore << "\n";
    cout << "yourScore: " << yourScore << "\n\n";

    cout << "Calling goodSwap()\n";
    goodSwap(&myScore, &yourScore);

    // cout << "myScore: " << myScore << "\n";
    // cout << "yourScore: " << yourScore << "\n\n";

    return 0;
}

void badSwap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void goodSwap(int* const myScore, int* const yourScore)
{
    // Сохраняем в temp значение, на которое указывает pX
    int temp = *myScore;
    cout << "temp us: " << temp << endl;
    cout << "\n";

    cout << "*myScore us: " << *myScore << endl;
    cout << "myScore us: " << myScore << endl;
    cout << "\n";

    // сохраняем значение, на которое указывает pY
    // по адресу, на который указывает pX
    *myScore = *yourScore;

    cout << "*yourScore us: " << *yourScore << endl;
    cout << "yourScore us: " << yourScore << endl;
    cout << "\n";

    cout << "*myScore us: " << *myScore << endl;
    cout << "myScore us: " << myScore << endl;
    cout << "\n";
    // сохраняем значение, на которое изначельно указывало pX
    // по адресу, на который указывает pY
    *yourScore = temp;

    cout << "temp us: " << temp << endl;
    cout << "\n";

    cout << "*yourScore us: " << *yourScore << endl;
    cout << "yourScore us: " << yourScore << endl;
    cout << "\n";
}