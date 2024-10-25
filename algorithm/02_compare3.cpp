// compare two vectors for permutatuin - elements the same but in different order
// 1. using equal - elements of v1 == elemets of v2
// 2. using equal + match(a, b)


#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

// two vector for comparing
vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'e', 'f', 'G', 'n'};
vector<char> v2 = {'B', 'd', 'j', 'e', 'f', 'A', 'g', 'h', 'c', 'i', 'f', 'g', 'n', 'e'};

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
    cout << "Demonstarte permutation functions" << endl;
    // check v1 and v2 for permutation using ==
    printMatch("is_permutation", is_permutation(v1.begin(), v1.end(), v2.begin()));
    // ceck for permutation using match function
    printMatch("is_permutation + match", is_permutation(v1.begin(), v1.end(), v2.begin(), match));
    cout << "*****************************************************" << endl;
    return 0;
}