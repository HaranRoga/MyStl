// Unique functions - Remove consecutive duplicates
// 1. using unique
// 2. using unique + func2
// 3. unique and copy to another location
// 4. unique + func2 and copy to another location

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// source vectors
vector<char> v1 = {'a', 'b', 'B', 'c', 'C', 'd', 'd'};
vector<char> v2 = {'a', 'b', 'B', 'c', 'C', 'd', 'd'};
vector<char> v3 = {'a', 'b', 'B', 'c', 'C', 'd', 'd'};
vector<char> v4 = {'a', 'b', 'B', 'c', 'C', 'd', 'd'};

// function to match capital and small letters
bool match(char a, char b) {
    return (toupper(a) == toupper(b));
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
    int n = v3.size();
    vector<char> v3dest(n, ' ');
    vector<char> v4dest;
    vector<char>::iterator itr;
    // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte unique function" << endl;
    // remove consequtive duplicates using unique
    cout << "Remove duplicates using unique and ==\n";
    printVector("Source vector v1", v1);
    itr = unique(v1.begin(), v1.end());
    v1.resize(distance(v1.begin(), itr));
    printVector("Remainig elements v1", v1);
    cout << endl;
    // remove duplicates ignore upper/lower cases
    cout << "Remove duplicates using match function\n";
    printVector("Source vector v2", v2);
    itr = unique(v2.begin(), v2.end(), match);
    v2.resize(distance(v2.begin(), itr));
    printVector("Remaining elements v2", v2);
    cout << endl;
    // remove duplicates creating a copy
    cout << "Remove duplicates store results in new vector\n";
    printVector("Source vector v3", v3);
    printVector("Empty vector v3dest", v3dest);
    itr = unique_copy(v3.begin(), v3.end(), v3dest.begin());
    v3.resize(distance(v3.begin(), itr));
    printVector("Remaining elements v3dest", v3dest);
    cout << endl;
    // remove duplicates using function creating a copy
    cout << "Remove duplicates using match function, store results using inserter\n";
    printVector("Source vector v4", v4);
    printVector("Empty vector v4dest", v4dest);
    unique_copy(v4.begin(), v4.end(), inserter(v4dest, v4dest.end()), match);
    printVector("Remaining elements v4dest", v4dest);
    cout << endl;
    return 0;
}