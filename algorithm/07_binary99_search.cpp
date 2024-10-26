// Customize binary search
// function for quick search of an element in sorted arry
// demonstrate O(logN) algorithm
// divide the array to 2 each time

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

// search function returns the index of found element or -1
int mySearch(vector<int>& v, int key)
{
    int low = 0, high = v.size() - 1, mid;
    while(low <= high)
    {
        mid = (high + low) / 2;
        if(v[mid] == key)
            return mid;
        if(key < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// use mySearch on several elements
int main() {
    int found;
   // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte customize binary search functions" << endl;
    printVector("Source vector for searches v1", v1);
    // mySearch - returns index of element in the vector
    cout << "mySearch - returns index of element in the vector\n";
    found = mySearch(v1, 4);
    if(found > -1)
    {
        cout << "Found element " << v1[found] << " at position " << found << endl;
    }
    else
    {
        cout << "element not found\n";
    }
    cout << endl;
    // search for non exists element - 5
    cout << "search for non exists element - 5\n";
    found = mySearch(v1, 5);
    if(found > -1)
    {
        cout << "Found element " << v1[found] << " at position " << found << endl;
    }
    else
    {
        cout << "element not found\n";
    }
    return 0;
}