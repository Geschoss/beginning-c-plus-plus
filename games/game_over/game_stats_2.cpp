// Программа Game Stats 2.0
// Демонстрирует арифметические операции с переменными
#include <iostream>
using namespace std;

int main() {
    unsigned int score = 5000;
    cout << "score: " << score << endl;
    // изменение значения переменной
    score = score + 100;
    cout << "score: " << score << endl;
    // комбинированный оператор присваивания
    score += 100;
    cout << "score: " << score << endl;
    // оператор инкремента
    int lives = 3;
    cout << "lives: " << lives++ << endl;
    cout << "lives: " << ++lives << endl;
     
    return 0;
}