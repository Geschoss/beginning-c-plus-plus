#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Critter {
public:
    Critter(const string& name = "");
    string getName() const;

private:
    string m_name;
};
Critter::Critter(const string& name)
    : m_name(name) {};
string Critter::getName() const { return m_name; };

class Farm {
public:
    Farm(int spaces = 1);
    void add(const Critter& aCritter);
    void rollCall();

private:
    vector<Critter> m_critters;
};
Farm::Farm(int spaces) { m_critters.reserve(spaces); };
void Farm::add(const Critter& aCritter) { m_critters.push_back(aCritter); };
void Farm::rollCall()
{

    for (vector<Critter>::const_iterator iter = m_critters.begin();
         iter != m_critters.end(); ++iter) {
        cout << iter->getName() << " here.\n";
    }
}

int main()
{
    Critter poochir("Poochir");
    cout << "My critter's name is " << poochir.getName() << endl;

    cout << "\nCreating critter farm.\n:";
    Farm farm(3);
    cout << "\nAdding thee critters to the farm.\n";
    farm.add(Critter("Moe"));
    farm.add(Critter("Larry"));
    farm.add(Critter("Curly"));

    cout << "\nCalling Roll...\n";
    farm.rollCall();
    return 0;
}
