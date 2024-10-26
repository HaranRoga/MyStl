// Quickly find elements in sorted sequences.
// These functions perform efficient, logarithmic time searches and comparisons in sorted ranges.
// The binary search functions can be used to determine if elements exist in a range, find their position, or determine their range of occurrence.
// binary_search
// lower_bound
// upper_bound
// equal_range

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// source vectors
vector<int> v1 = {1, 2, 3, 4, 4, 4, 7, 8, 8, 10, 11, 12, 13, 14, 15};

// function for printing vectors
void printVector(string str, vector<int>& v) {
    cout << "vector " << str << ": " ;
    for(int n : v)
    {
        cout << n << ", ";
    }
    cout << endl;
}

int main() {
    vector<int>::iterator itr1, itr2;
    pair<vector<int>::iterator, vector<int>::iterator> rng;
    int n1, n2;
   // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte binary search functions" << endl;
    // binary_search - determine if value exists in vector
    cout << "binary_search - determine if value exists in vector\n";
    printVector("Vector v1", v1);
    if(binary_search(v1.begin(), v1.end(), 7))
    {
        cout << "Value 7 exist in v1\n";
    }
    else
    {
        cout << "Value 7 not exists in v1\n";
    }
    cout << endl;
    // lower_bound - iterator to smallest element, not smaller than val
    cout << "lower_bound - iterator to smallest element, not smaller than val\n";
    itr1 = lower_bound(v1.begin(), v1.end(), 4);
    cout << "Value of " << *itr1 << " at position " << itr1 - v1.begin() << endl;
    cout << endl;
    // upper_bound - iterator to biggest element, smaller than val
    cout << "upper_bound - iterator to biggest element, smaller than val\n";
    itr2 = upper_bound(v1.begin(), v1.end(), 4);
    cout << "Value of " << *itr2 << " at position " << itr2 - v1.begin() << endl;
    cout << endl;
    // equal_range - pair of iterators surrounding val
    cout << "equal_range - pair of iterators surrounding val\n";
    rng = equal_range(v1.begin(), v1.end(), 8);
    n1 = rng.first - v1.begin();
    n2 = rng.second - v1.begin();
    cout << "Value of " << *rng.first << " is between " << n1 << " and " << n2 << endl;
    cout << endl;
    return 0;
}