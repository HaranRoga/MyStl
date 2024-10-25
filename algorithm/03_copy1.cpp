// copy from one vector to another
// 1. using v1 pointers beging, end + v2 begin
// 2. using v1, v2 pointers begin + length
// 3. conditional copy using func1
// 4. backwards copy (end to start)


#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

// Source vector
vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'e', 'f', 'G', 'n'};

// function to select only small letters
bool match(char a) {
    return (a != toupper(a));
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

int main() {
    // copy vectors using predefined size
    int vSize = v1.size();
    // basic copy function
    vector<char> v2(vSize);
    copy(v1.begin(), v1.end(), v2.begin());
    // copy using number of elements
    vector<char> v3(vSize - 5);
    copy_n(v1.begin(), vSize - 5, v3.begin());
    // slelctive copy - only small characters
    vector<char> v4(vSize, ' ');
    copy_if(v1.begin(), v1.end(), v4.begin(), match);
    // backward copy - start for last element
    vector<char> v5(vSize);
    copy_backward(v1.begin(), v1.end(), v5.end());

    // print results:
    cout << "*****************************************************" << endl;
    cout << "Demonstarte copy functions" << endl;
    printVector("Source v1", v1);
    printVector("Pointers copy v2", v2);
    printVector("Copy length v3", v3);
    printVector("Conditional copy v4", v4);
    printVector("Backward copy v5", v5);
    cout << "*****************************************************" << endl;
    return 0;
}