#include <iostream>
using namespace std;

void func();

int main()
{
    int var = 5; // local variable in main
    cout << "In main() var is: " << var << "\n\n";

    func();
    cout << "Back in main() vat is: " << var << "\n\n";

    {
        cout << "In main() in a new scope var is: " << var << "\n\n";
        cout << "Creating new var in new scope.\n";

        int var = 10; // overade
        cout << "In main() a new scope var is: " << var << "\n\n";
    }
    cout << "At end of main() var create in new scope no longer exists.\n";
    cout << "At end of main() var is: " << var << "\n\n";

    return 0;
}

void func()
{
    int var = -1; // local var in func
    cout << "In func() var is: " << var << "\n\n";
}