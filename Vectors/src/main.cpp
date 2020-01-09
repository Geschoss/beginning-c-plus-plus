#include <iostream>
#include <vector>

using namespace std;


int main() {

    vector <char> vowels {'a', 'v', 'g', 'g'};
    vector <int> numbers {1, 2, 3};
    vector <int> test_scores (3, 100);
    vector <int> test_srore (3);

    cout << "Scores: " << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << "Size: " << test_scores.size() << endl;


    int score_to_add {5};

    test_scores.push_back(score_to_add);

    cout << test_scores.size() << endl;
    cout << test_scores.at(3) << endl;

    // Example of a 2D-vector

    vector <vector<int>> movie_rating
    {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };

    cout << movie_rating.at(0).at(1) << endl;
    
    return 0;
}