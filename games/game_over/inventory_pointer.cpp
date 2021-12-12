#include <iostream>
#include <string>
#include <vector>

using namespace std;

string* ptrToElement(vector<string>* const pVec, int i);
string* getBadPointer();

int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    // отобрпажаем строковый элемент, на который направлен возвращаемый
    // указатель
    cout << "Sending hte object pointer to by returned pointer to cout:\n";
    cout << *(ptrToElement(&inventory, 0)) << "\n\n";

    // присввивает одни указатель другому - малозатратная операция
    cout << "Assingning thee returned pointer to another pointer.\n";
    string* pStr = ptrToElement(&inventory, 1);
    cout << *pStr << "\n\n";

    // копируем строковый объект - затратная операция присваивания
    cout << "Assingning object pointed to by pointer tto a string object.\n";
    string str = *(ptrToElement(&inventory, 2));
    cout << str << endl;

    // изменение строкового объекта посредством возвращенного указателя
    cout << "Alterning an object through a returned pointer.\n";
    *pStr = "Healing Potion";
    cout << inventory[1] << endl;

    string* badPointer = getBadPointer();
    cout << "badPointer is: " << badPointer << endl;
    cout << "*badPointer is: " << *badPointer << endl;

    return 0;
}

string* ptrToElement(vector<string>* const pVec, int i)
{
    return &((*pVec)[i]);
}

string* getBadPointer()
{
    string local = "This string will cease to exist once the function ends.";
    string* pLocal = &local;

    return pLocal;
}