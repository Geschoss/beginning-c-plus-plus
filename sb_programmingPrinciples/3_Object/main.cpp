#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter a floating-point value: ";
    int n;
    cin >> n;
    cout << "n == " << n
         << "\nn+1 == " << n + 1
         << "\nthree times n == " << 3 * n
         << "\ntwice n == " << n + n
         << "\nnsquared == " << n * n
         << "\n half of n == " << n / 2
         << "\n % of n == " << n % 2
         << "\nsquare root of n == " << sqrt(n)
         << '\n';

    // Strings

    cout << "Please  enter your first and second name\n";
    string first;
    string second;
    cin >> first >> second;
    if (first == second)
    {
        cout << "that's the same name twice\n";
    }
    if (first < second)
    {
        cout << first << " is aplphavetically before " << second << '\n';
    }
    if (first > second)
    {
        cout << first << " is alphabeticalyy after " << second << '\n';
    }
    string name = first + ' ' + second;
    cout << "Hello, " << name << '\n';

    int number_of_words = 0;
    string previous = " ";
    string current;
    while (cin >> current)
    {
        ++number_of_words;
        if (previous == current)
        {
            cout << "word number " << number_of_words
                 << " repeated word: " << current
                 << '\n';
        }
        previous = current;
    }

    return 0;
}