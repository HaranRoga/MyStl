// sorting function - rearrange elements in containers in a specific order
// Sort elements in range
// Sort elements preserving order of equivalents
// Partially sort elements in range
// Copy and partially sort range
// Sort element in range
// Check whether range is sorted
// Find first unsorted element in range

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

// source vectors
vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

// function to sort odds before evens
bool oddsFirst(int a, int b) {
    if(a % 2 == b % 2)
    {
        return a < b;
    }
    else 
    {
        return (a % 2 == 1);
    }
}

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
    unsigned seed = 0;
    vector<int> v2(10,0);
   // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte sorting functions" << endl;
    // demonstrate sort function
    cout << "demonstrate sort function\n";
    shuffle(v1.begin(), v1.end(),default_random_engine(seed));
    printVector("Source vector v1", v1);
    cout << "vector v1 is " << (is_sorted(v1.begin(), v1.end())? "sorted\n" : "not sorted\n");
    sort(v1.begin(), v1.end());
    printVector("Sorted v1", v1);
    cout << "vector v1 is " << (is_sorted(v1.begin(), v1.end())? "sorted\n" : "not sorted\n");
    cout << endl;
    // demonstrate sort preserving order odds first
    cout << "demonstrate sort preserving order odds first\n";
    cout << "vector v1 according to oddsFirst " << 
        (is_sorted(v1.begin(), v1.end(), oddsFirst)? "sorted\n" : "not sorted\n");
    stable_sort(v1.begin(), v1.end(), oddsFirst);
    printVector("v1 sorted by odds first", v1);
    cout << "vector v1 according to oddsFirst " << 
        (is_sorted(v1.begin(), v1.end(), oddsFirst)? "sorted\n" : "not sorted\n");
    cout << endl;
    // demonstrate partial sort default order
    cout << "demonstrate partial sort default order\n";
    partial_sort(v1.begin(), v1.begin() + 6, v1.end());
    printVector("v1 6 first element sorted", v1);
    cout << "Element not ordered: " << (*is_sorted_until(v1.begin(), v1.end())) << endl;
    cout << endl;
    // demonstrate partioal sort copy
    cout << "demonstrate partioal sort copy\n";
    printVector("Source vector v2", v2);
    partial_sort_copy(v1.begin(), v1.end(), v2.begin(), v2.end());
    printVector("v2 sorted", v2);
    cout << endl;
    // demonstrate nth element
    cout << "demonstrate nth element\n";
    printVector("Current status of v1", v1);
    nth_element(v1.begin(), v1.begin() + 12, v1.end());
    printVector("v1 after element 12", v1);
    cout << endl;
    return 0;

}