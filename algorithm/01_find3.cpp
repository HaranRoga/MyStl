// finding subsequence v2 in vector v1 returnng iterator
// 1. using search (v1.begin()-end(), v2.begin()-end())
// 2. using search() + match(a, b)
// 3. using find_end()
// 4. using find_end() + match(a, b)

#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'e', 'f', 'G', 'n'}; // Searched vector
vector<char> v2 = {'E', 'f', 'g'}; // Data to be searched for

// function to match capital and small letters
bool match(char a, char b) {
    return (toupper(a) == toupper(b));
}

// function to convert found caracter into a printable string
// if it exists in v1 - returns the caracter
// else - return "n/a"
string toPrint(vector<char>::iterator itr) {
    return itr != v1.end()? string(1, *itr): "n/a";
}

int main() {
    // searching for subset in an array
    auto itSrch1 = search(v1.begin(), v1.end(), v2.begin(), v2.end());
    // searching for subset in an array using customize function
    auto itSrch2 = search(v1.begin(), v1.end(), v2.begin(), v2.end(), match);
    // searching for last subset in an array
    auto itSrch3 = find_end(v1.begin(), v1.end(), v2.begin(), v2.end());
    // searching for lats subset using customize function
    auto itSrch4 = find_end(v1.begin(), v1.end(), v2.begin(), v2.end(), match);

    cout << "found elements: " << toPrint(itSrch1)
        << ", " << toPrint(itSrch2)
        << ", " << toPrint(itSrch3)
        << ", " << toPrint(itSrch4)
        << endl;
    return 0;
}