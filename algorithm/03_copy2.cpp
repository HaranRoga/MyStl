// swap between elements
// 1. swap elements by value
// 2. swap two vectors
// 3. swap elements by pointers


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Source vectors
vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'e', 'f', 'G', 'n'};
vector<char> v2 = {'B', 'd', 'j', 'e', 'f', 'A', 'g', 'h', 'c', 'i', 'f', 'g', 'n', 'e'};
// Source elements
char a1 = 'A', a2 = 'B';
char b1 = 'c', b2 = 'd';

// function for printing vectors
void printVector(string str, vector<char>& v) {
    cout << "vector " << str << ": " ;
    for(char ch : v)
    {
        cout << ch << ", ";
    }
    cout << endl;
}

// function for printing elements
void printElements(string str, char a, char b) {
    cout << "Elements " << str << ": " << a << ", " << b << endl;
}

int main() {
    // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte swap functions" << endl;
    // swap elements values
    printElements("Swap initial a1, a2", a1, a2);
    swap(a1, a2);
    printElements("Swapped values a1, a2", a1, a2);
    cout << endl;
    // swap vectors
    printVector("V1 initial state", v1);
    printVector("V2 initial state", v2);
    cout << endl;
    swap_ranges(v1.begin(), v1.end(), v2.begin());
    printVector("V1 swapped", v1);
    printVector("V2 swapped", v2);
    cout << endl;
    // swap two pointers
    printElements("Pointers initial b1, b2", b1, b2);
    iter_swap(&b1, &b2);
    printElements("Swapped pointers b1, b2", b1, b2);
    cout << "*****************************************************" << endl;
    return 0;
}