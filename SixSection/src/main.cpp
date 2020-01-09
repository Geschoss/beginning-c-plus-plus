#include <iostream>
#include <climits>

using namespace std;

template <typename T> 

void log(T str) {
    cout << str << endl;
}

int main() 
{

    char middle_initial {'J'};
    cout << "My middle initial " << middle_initial << endl;

    unsigned short int exam_score {55};

    log("My exam score was" + to_string(exam_score));

    cout << sizeof(char);
    
    const int month = 12;

    return 0;
}