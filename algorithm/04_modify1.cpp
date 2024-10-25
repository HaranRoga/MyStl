// replace values of elements with another value
// 1. replace occurence of a value with other
// 2. replace using match function with other
// 3. replace value storing the results in different array
// 4. replace using match storing results in different array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// source vectors
vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
vector<char> v2 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
vector<int> v3 = {1, 2, 3, 1, 2, 3, 1, 2, 3};
vector<int> v4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// match function for character
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i';
}

// match function for int
int isMult3(int n) {
    return (n % 3 == 0);
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
    int n = v3.size();
    vector<int> v3dest(n, 0);
    vector<int> v4dest;
    // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte replace function" << endl;
    // replace element value with another (f to x)
    cout << "Replace character f with x\n";
    printVector("Soruce vector v1", v1);
    replace(v1.begin(), v1.end(), 'f', 'x');
    printVector("Replaced vector v1", v1);
    cout << endl;
    // replace using match function (change vowels to -)
    cout << "Replace vowels with sign -\n";
    printVector("Source vector v2", v2);
    replace_if(v2.begin(), v2.end(), isVowel, '-');
    printVector("Replaced vector v2", v2);
    cout << endl;
    // replace 3 with 4 to different destination (predefined space)
    cout << "Replace 3 with 4 and copy\n";
    printVector("Source vector v3", v3);
    printVector("Initialized dest vector v3dest", v3dest);
    replace_copy(v3.begin(), v3.end(), v3dest.begin(), 3, 4);
    printVector("Destination vector v3dest", v3dest);
    cout << endl;
    // replace multiples of 3 with 0 to different destination (using inserter)
    cout << "Reset multiples of 3 with copy\n";
    printVector("Source vector v4", v4);
    printVector("Initialized dest vector v4dest", v4dest);
    replace_copy_if(v4.begin(), v4.end(), inserter(v4dest, v4dest.begin()), isMult3, 0);
    printVector("Destination vector v4dest", v4dest);
    cout << endl;

    return 0;
}