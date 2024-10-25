// Reverse and rotate - changing elements order
// 1. reverse       -   vector updated with reverse ordered elements
// 2. reverse_copy  -   results stored in different vector
// 3. rotate        -   vector updated with left rotated elements
// 4. rotate_copy   -   rotated vector stored in different vector

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// source vectors
vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
vector<char> v2 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
vector<char> v3 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
vector<char> v4 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

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
    vector<char> v2dest;
    vector<char> v4dest;
    // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte reverse and rotate functions" << endl;
    // reverse vector elements order inplace
    cout << "reverse vector elements order inplace\n";
    printVector("Source order or v1", v1);
    reverse(v1.begin(), v1.end());
    printVector("Results of v1", v1);
    cout << endl;
    // reverse vector elements order to other destinanion
    cout << "reverse vector elements order to other destinanion\n";
    printVector("Source order or v2", v2);
    printVector("Empty vector v2dest", v2dest);
    reverse_copy(v2.begin(), v2.end(), inserter(v2dest, v2dest.end()));
    printVector("Reversed vector v2dest", v2dest);
    cout << endl;
    // left rotating vector 2 places inplace
    cout << "left rotating vector 2 places inplace\n";
    printVector("Source order or v3", v3);
    rotate(v3.begin(), v3.begin() + 2, v3.end());
    printVector("Rotated vector v3", v3);
    cout << endl;
    // left rotating vector 2 places to different destination
    cout << "left rotating vector 2 places to different destination\n";
    printVector("Source order or v4", v4);
    printVector("Empty vector v4dest", v4dest);
    rotate_copy(v4.begin(), v4.begin() + 2, v4.end(), inserter(v4dest, v4dest.end()));
    printVector("Rotated vector v4dest", v4dest);
    cout << endl;
    return 0;
}