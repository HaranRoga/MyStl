// compare two vectors for equality
// 1. using equal - elements of v1 == elemets of v2
// 2. using equal + match(a, b)


#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

// two vector for comparing
vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'e', 'f', 'G', 'n'};
vector<char> v2 = {'A', 'B', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'e', 'f', 'g', 'n'};

// function to match capital and small letters
bool match(char a, char b) {
    return (toupper(a) == toupper(b));
}

// function for printing results
void printMatch(string str, bool results) {
    cout << "Results of " << str << " are: " << 
        (results? "Positive" : "Negative") << endl;
}

int main() {
    cout << "*****************************************************" << endl;
    cout << "Demonstarte equal / lex.compare functions" << endl;
    // compare the vectors using ==
    printMatch("equal", equal(v1.begin(), v1.end(), v2.begin()));
    // compare the vaecors using match function
    printMatch("equal + match", equal(v1.begin(), v1.end(), v2.begin(), match));
    // lexicographical compare the vectors (abc > acb)
    printMatch("lex. v1 > v2", lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
    // lexicographical using match function
    printMatch("lex. v1 > v2 + match", lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), match));
    cout << "*****************************************************" << endl;

    return 0;
}