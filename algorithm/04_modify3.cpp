// remove elements from vector by value or by function
// 1. remove value from the vector
// 2. remove elements by func1
// 3. remove value and copy to different vector
// 4. remove by func1 and copy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// source vectors
vector<int> v1 = {1, 2, 3, 1, 2, 3, 1, 2, 3};
vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> v3 = {1, 2, 3, 1, 2, 3, 1, 2, 3};
vector<int> v4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};


// match function for int
int isMult3(int n) {
    return (n % 3 == 0);
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
    int n = v3.size();
    vector<int> v3dest(n, 0);
    vector<int> v4dest;
    // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte remove function" << endl;
    // remove value form vector
    printVector("Source vector v1", v1);
    auto itr = remove(v1.begin(), v1.end(), 3);
    printVector("Remaining items v1", v1);
    cout << endl;
    // remove values that multiles of 3
    printVector("Source vector v2", v2);
    itr = remove_if(v2.begin(), v2.end(), isMult3);
    printVector("Remaining items v2", v2);
    cout << endl;
    // remove values end copy to different destination
    printVector("Source vector v3", v3);
    printVector("Empty vector v3dest", v3dest);
    remove_copy(v3.begin(), v3.end(), v3dest.begin(), 2);
    printVector("Fillded vector v3dest", v3dest);
    cout << endl;
    // remove multiples of 3 and copy using inserter
    printVector("Source vector v4", v4);
    printVector("Empty vector v4dest", v4dest);
    remove_copy_if(v4.begin(), v4.end(), inserter(v4dest, v4dest.end()), isMult3);
    printVector("Fillded vector v4dest", v4dest);
    cout << endl;
    return 0;
}