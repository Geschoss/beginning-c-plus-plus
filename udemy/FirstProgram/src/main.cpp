#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::to_string;

template <typename T> 

void log(T str) {
    cout << str << endl;
}

int main() 
{
    int favorite_number;
    log("Enter you favorite number between 1 and 100");
    
    cin >> favorite_number;

    if (favorite_number > 18)
        log("Пес " + to_string(favorite_number));
    else 
        log(favorite_number);
    
    while (favorite_number != 0)
    {
        log("while " + to_string(favorite_number));
        favorite_number--;
    }
    
    for (int i=0; i < 5; i++) 
        log("for " + to_string(i));

    // this is comment

    /*
    sdfsdf 
    sdfsdf
    */

    return 0;
}