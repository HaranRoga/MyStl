// Customize binary search: rotated array
// The principal is the same as binary search,
// but since the array is rotated, it is not sorted.
// pivot element (smalles right to the biggest) is in one side of the array
// so first find the sorted side, and compare the key to it

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// source vectors
vector<int> v1 = {8, 8, 10, 11, 12, 13, 14, 15, 1, 2, 3, 4, 4, 4, 7};

// function for printing vectors
void printVector(string str, vector<int>& v) {
    cout << "vector " << str << ": " ;
    for(int n : v)
    {
        cout << n << ", ";
    }
    cout << endl;
}

// search function in sorted rotated array
int mySearch(vector<int>& v, int key) {
    int low = 0, high = v.size() - 1, mid;
    while(low <= high)
    {
        mid = (high + low) / 2;
        // case1: check if key found
        if(v[mid] == key)
            return mid;
        // case2: lower part sorted
        else if(v[low] < v[mid])
        {
            // check if key in lower part range
            if(v[low] <= key && key < v[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // case3: higher part sorted
        else
        {
            // check if key in higher part range
            if(v[mid] < key && key <= v[high])
            {
                low = mid - 1;
            }
            else
            {
                high = mid + 1;
            }
        }
    }
    // key not found
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