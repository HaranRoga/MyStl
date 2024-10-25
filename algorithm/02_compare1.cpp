// check vector elements using customize function
// 1. using all_of + match(a)
// 2. using any_of + match(a)
// 3. using none_of + match(a)

#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

// two vector for comparing
vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'e', 'f', 'G', 'n'};

// function to match capital and small letters
bool match(char a) {
    return ('a' <= a && a <='z');
}

// function for printing results
void printMatch(string str, bool results) {
    cout << "Results of " << str << " are: " << 
        (results? "Positive" : "Negative") << endl;
}

int main() {
    cout << "*****************************************************" << endl;
    cout << "Demonstarte xxx_of functions" << endl;
    // check if all elements small letters (a-z)
    printMatch("all_of", all_of(v1.begin(), v1.end(), match));
    // check if any of the elements is small letter
    printMatch("any_of", any_of(v1.begin(), v1.end(), match));
    // check if no element is small letter
    printMatch("none_of", none_of(v1.begin(), v1.end(), match));
    cout << "*****************************************************" << endl;
    
    return 0;
}