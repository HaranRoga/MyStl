// Shuffle functions - changing elements order randomly
// 1. shuffle        -   rearange elements order using specified function
// 2. random_shuffle -   rearange elements order using default method

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

// source vectors
vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
vector<char> v2 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

// function for printing vectors
void printVector(string str, vector<char>& v) {
    cout << "vector " << str << ": " ;
    for(char ch : v)
    {
        cout << ch << ", ";
    }
    cout << endl;
}

int main() {
    unsigned seed = 0;
    // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte shuffle functions" << endl;
    // rearange elements order using specified function
    cout << "rearange elements order using specified function\n";
    printVector("Source order or v1", v1);
    shuffle(v1.begin(), v1.end(), default_random_engine(seed));
    printVector("Results of v1", v1);
    cout << endl;
    // rearange elements order using default method
    cout << "rearange elements order using default method\n";
    printVector("Source order or v2", v2);
    random_shuffle(v2.begin(), v2.end());
    printVector("Results of v2", v2);
    cout << endl;
    return 0;
}
