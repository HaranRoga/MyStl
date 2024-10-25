// finding element in a vector retuning iterator
// 1. using find - element == value
// 2. using match(element) == true
// 3. using match(element) == false

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v1 = {1, 2, 3, 4, 5, 6}; //Vector for search demonstrations

// function to determine the search condition
bool match(int a) {
  return a == 3;
}

// function for printing vectors
void printVector(string str, vector<int>& v) {
    cout << "vector " << str << ": " ;
    for(int val : v)
    {
        cout << val << ", ";
    }
    cout << endl;
}

// demonstrate using find functions
int main() {
    // basic find - finding element in an array
    auto itFind1 = find(v1.begin(), v1.end(), 3);
    // finding element using dedicated function
    auto itFind2 = find_if(v1.begin(), v1.end(), match);
    // finding element that not meets function conditions (inline)
    auto itFind3 = find_if_not(v1.begin(), v1.end(), [](int a){return a != 3;} );

    cout << "*****************************************************" << endl;
    cout << "Demonstarte find function" << endl;
    cout << "found using find: " << *itFind1 << endl;
    cout << "found using match(a): " << *itFind2 << endl;
    cout << "found using if-not(!=3):" << *itFind3 << endl;
    cout << "*****************************************************" << endl;
   return 0;
}