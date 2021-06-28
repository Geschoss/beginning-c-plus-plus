#include <iostream>

using namespace std;

int main() 
{
    int small_room_count {0};
    int large_room_count {0};
    const int price_per_small_rooms {25};
    const int price_per_large_rooms {35};
    const double tax_rate {0.06};

    cout << "Enter small room count: " << endl;
    cin >> small_room_count;
    cout << "Enter lagre room count: " << endl;
    cin >> large_room_count;

    int small_rooms_cost = small_room_count * price_per_small_rooms;
    int large_rooms_cost = large_room_count * price_per_large_rooms;

    double small_rooms_tax = small_rooms_cost * tax_rate;
    double large_rooms_tax = large_rooms_cost * tax_rate;

    double total_cost = small_rooms_cost + large_rooms_cost;
    double total_tax = small_rooms_tax + large_rooms_tax;

    cout << "Estimate for carpet cleaning service:" << endl;
    cout << "Number of small rooms: " << small_room_count << endl;
    cout << "Number of large rooms: " << large_room_count << endl;
    cout << "Price per small room: " << price_per_small_rooms << endl;
    cout << "Price per large room: " << price_per_large_rooms << endl;
    cout << "Cost: $" << total_cost << endl;
    cout << "Tax: $" << total_tax << endl;
    cout << "=======================" << endl;
    cout << "Total estimate: $" << total_cost + total_tax << endl;
    cout << "This estimate is valid for 30 days";
    
    return 0;
}
