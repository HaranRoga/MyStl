// insert element of one array to another
// 1. copy using inserter
// 2. unary transform using inserter
// 3. bibary transform using inserter

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Source vectors
vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'e', 'f', 'G', 'n'};
vector<int> v4 = {1, 2, 3, 4, 5};
vector<int> v5 = {6, 7, 8, 9, 10};

// function convert character to lower letter
char chLower(char ch) {
    return tolower(ch);
}

// function for adding two integers
int add(int n1, int n2) {
    return n1 + n2;
}

// function for printing vectors
void printVector(string str, vector<char>& v) {
    cout << "vector " << str << ": " ;
    for(char ch : v)
    {
        cout << ch << ", ";
    }
    cout << endl;
}
void printVector(string str, vector<int>& v) {
    cout << "vector " << str << ": " ;
    for(int n : v)
    {
        cout << n << ", ";
    }
    cout << endl;
}

int main() {
    int vLen = v1.size();
    vector<char> v2;
    vector<char> v3;
    vector<int> v6;
    // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte inserter function" << endl;
    // inserter function inside copy
    printVector("source vector v1", v1);
    printVector("empty vector v2", v2);
    copy(v1.begin(), v1.end(), inserter(v2, v2.end()));
    printVector("After copying v2", v2);
    cout << endl;
    // inserter function inside unary transform
    printVector("empty vector v3", v3);
    transform(v1.begin(), v1.end(), inserter(v3, v3.end()), chLower);
    printVector("transformed to lower v3", v3);
    cout << endl;
    // inserter function inside binary transform
    printVector("Integers v4", v4);
    printVector("Integers v5", v5);
    printVector("empty vector v6", v6);
    transform(v4.begin(), v4.end(), v5.begin(), inserter(v6, v6.end()), add);
    printVector("added vectors v6", v6);
    cout << "*****************************************************" << endl;
    return 0;
}