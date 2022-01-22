#include <iostream>

double square(double x) { return x * x; }

void print_square(double x)
{
    std::cout << "Квадрат " << x << " равен " << square(x) << "\n";
}

int main()
{
    print_square(1.234);

    return 0;
}