// fill vector with defined or generated values
// 1. fill array using begin + end pointers
// 2. fill array using begin pointer + length
// 3. fill begin to end with generated numbers
// 4. fill begin to length with generated numbers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// generator function - generate lower case letters a - z
char genLower()
{
    static int i=0;
    return 'a' + i++ % 26;
}

char genUpper()
{
    static int i=0;
    return 'A' + i++ % 26;
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
    vector<char> v1(20, ' ');
    vector<char> v2(20, ' ');
    vector<char> v3(20, ' ');
    vector<char> v4(20, ' ');
    // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte fill adn generate functions" << endl;
    // fill using begin + end pointers
    cout << "Fill array using pointers\n";
    printVector("Source vector v1", v1);
    fill(v1.begin(), v1.end(), '#');
    printVector("Filled v1", v1);
    cout << endl;
    // fill using begin + length
    cout << "Fill array using begin + length\n";
    printVector("Source vector v2", v2);
    fill_n(v2.begin(), 20, '%');
    printVector("Filled v2", v2);
    cout << endl;
    // generate lower case letters
    cout << "Generate lower case letters using pointers\n";
    printVector("Source vector v3", v3);
    generate(v3.begin(), v3.end(), genLower);
    printVector("Generated letters v3", v3);
    cout << endl;
    // generate upper case letters
    cout << "Generate upper case letters using length\n";
    printVector("Source vector v4", v4);
    generate_n(v4.begin(), 20, genUpper);
    printVector("Generated letters v4", v4);
    cout << endl; 

    return 0;
}