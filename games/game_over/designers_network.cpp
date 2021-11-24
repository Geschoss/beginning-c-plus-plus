#include <iostream>
#include <string>
using namespace std;

int main()
{
    string username;
    string password;
    bool succes;
    cout << "\tGame Designer's Network\n";
    do {
        cout << "\nUsername: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "S.Meire" && password == "civilization") {
            cout << "\nHey Sid.";
            succes = true;
        } else if (username == "S.Miymoto" && password == "mariobros") {
            cout << "\n What's up, Shigeru?";
            succes = true;
        } else if (username == "W.Wright" && password == "thesims") {
            cout << "\nHow goes it, Will?";
            succes = true;
        } else if (username == "guest" || password == "guest") {
            cout << "\nWellcome, newbye!";
            succes = true;
        } else {
            cout << "\nYour login failed.";
            succes = false;
        }
    } while (!succes);

    return 0;
}