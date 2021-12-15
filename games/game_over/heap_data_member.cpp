#include <iostream>
#include <string>

using namespace std;

class Critter {
public:
    Critter(const string& name = "", int age = 0);
    Critter(const Critter& c);
    ~Critter();
    Critter& operator=(const Critter& c);

    void greet();

private:
    string* m_pName;
    int m_age;
};
Critter::Critter(const string& name, int age)
{
    cout << "Constructor called\n";
    m_pName = new string(name);
    m_age = age;
}
Critter::~Critter()
{
    cout << "Destructor called\n";
    delete m_pName;
}
Critter::Critter(const Critter& c)
{
    cout << "Copy Constructor called\n";
    m_pName = new string(*(c.m_pName));
    m_age = c.m_age;
}
Critter& Critter::operator=(const Critter& c)
{
    cout << "Overloaded Assigment Operator called\n";
    if (this != &c) {
        delete m_pName;
        m_pName = new string(*(c.m_pName));
        m_age = c.m_age;
    }

    return *this;
}
void Critter::greet()
{
    cout << "I'm " << *m_pName << " and I'm " << m_age << " years old. ";
    cout << "&m_pName: " << &m_pName << endl;
}
void testDestructor();
void testCopyConstructor(Critter aCopy);
void testAssignmentOp();

int main()
{
    testDestructor();
    cout << endl;

    Critter crit("Poochir", 5);
    crit.greet();

    testCopyConstructor(crit);
    crit.greet();
    cout << endl;

    testAssignmentOp();

    return 0;
}

void testDestructor()
{
    Critter toDestroy("Rover", 3);
    toDestroy.greet();
}
void testCopyConstructor(Critter aCopy) { aCopy.greet(); }
void testAssignmentOp()
{
    Critter crit1("crit1", 7);
    Critter crit2("crit2", 9);
    crit1 = crit2;
    crit1.greet();
    crit2.greet();
    cout << endl;

    Critter crit3("crit", 11);
    crit3 = crit3;
    crit3.greet();
}