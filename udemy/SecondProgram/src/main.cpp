#include <iostream>
using namespace std;

template <typename T> 

void log(T str) {
    cout << str << endl;
}

int factorial(int x) {
    int y = 1;
    for (int i = 1; i <= x; i++) {
          y *= i;
    }

    return y;
}

int inner_fact(int result, int count, int x) {
    if (count == x) {
        return result;
    }
    count++;

    return inner_fact(result * count, count, x);
}

int rect_fact(int x) {
    return inner_fact(1, 1, x);
}

int main() 
{
    int i;
    for (i = 0; i <= 10; i++) {
        // int res = factorial(i);
        log("i = " + to_string(i));
        // log("res = " + to_string(res));
        // log(rect_fact(i));
    }

    while(i != 10) {
        log("i = " + to_string(i));
        break;
    }
    return 0;
}