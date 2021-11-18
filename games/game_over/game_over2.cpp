#include <iostream>
#include <string>
using namespace std;

char switchChar(char c)
{
    switch (c)
    {
    case '5':
        return 'S';
    case '1':
        return 'I';
    case '0':
        return 'O';
    default:
        return c;
    }
}

int main()
{
    string str = "R0BERT MERLE - THE DAY 0F THE D0LPH1N";

    for (int i = 0; i < str.length(); i++)
    {
        str[i] = switchChar(str[i]);
    }

    cout << str << endl;

    string a = "4";
    string b = "50";
    string r = to_string(stoi(a) + stoi(b));
    cout << "result: " << r;

    return 0;
}