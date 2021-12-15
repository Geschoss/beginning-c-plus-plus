#include <iostream>
#include <string>

using namespace std;

class Critter {
    friend void peek(const Critter& aCritter);
    friend ostream& operator<<(ostream& os, const Critter& aCritter);

public:
    Critter(const string& name = "");

private:
    string m_name;
};

Critter::Critter(const string& name)
    : m_name(name) {};
void peek(const Critter& aCritter);
ostream& operator<<(ostream& os, const Critter& aCritter);

int main()
{
    Critter crit("Poochie");
    cout << "Calling peek() to access crit's private data member. m_name: \n";
    peek(crit);
    cout << "\nSending crit object to cout with the << operator:\n";
    cout << crit;

    return 0;
}

void peek(const Critter& aCritter) { cout << aCritter.m_name << endl; }

ostream& operator<<(ostream& os, const Critter& aCritter)
{
    os << "Critter Object - ";
    os << "m_name: " << aCritter.m_name;

    return os;
}