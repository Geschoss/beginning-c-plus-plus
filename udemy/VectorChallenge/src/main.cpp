#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec1;
    vector<int> vec2;

    vec1.push_back(10);
    vec1.push_back(20);

    cout << "vec1.at(0): " << vec1.at(0) << endl;
    cout << "vec1.at(1): " << vec1.at(1) << endl;
    cout << "vec1.size(): " << vec1.size() << endl;

    vec2.push_back(100);    
    vec2.push_back(200);

    cout << "vec2.at(0): " << vec2.at(0) << endl;    
    cout << "vec2.at(1): " << vec2.at(1) << endl;
    cout << "vec2.size(): " << vec2.size() << endl;
        
    vector<vector<int>> vector_2d;

    vector_2d.push_back(vec1);
    vector_2d.push_back(vec2);

    cout << "{" << vector_2d.at(0).at(0) <<" : " << vector_2d.at(0).at(1) << "}" << endl;
    cout << "{" << vector_2d.at(1).at(0) <<" : " << vector_2d.at(1).at(1) << "}" << endl;

    vec1.at(0) = 100;
    vec1.at(1) = 200;
    cout << "vec1.at(0): " << vec1.at(0) << endl;
    cout << "vec1.at(1): " << vec1.at(1) << endl;

    cout << "{" << vector_2d.at(0).at(0) <<" : " << vector_2d.at(0).at(1) << "}" << endl;
    cout << "{" << vector_2d.at(1).at(0) <<" : " << vector_2d.at(1).at(1) << "}" << endl;
    
    return 0;
}