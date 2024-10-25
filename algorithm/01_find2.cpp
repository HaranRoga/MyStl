// finding adjastent elements in vector v1
// 1. adjastent find - any adjastent element
// 2. search_n() - compare to spesific value
// 3. search_n() + match(a, b) - copare using scustomized function

#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'J', 'l', 'm', 'n'}; // Searched vector

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

// demonstrate using search functions
int main() {
    // find duplicate neibors elements in the array, return the first
    auto itFind1 = adjacent_find(v1.begin(), v1.end());
    // searching for value appearing consecutive times
    auto itFind2 = search_n(v1.begin(), v1.end(), 2, 'j');
    // searching for value appearing cinsecutive times using cusotmize function
    auto itFind3 = search_n(v1.begin(), v1.end(), 2, 'j', match);

    cout << "found elements: " << toPrint(itFind1)
        << ", " << toPrint(itFind2)
        << ", " << toPrint(itFind3)
        << endl;
    return 0;
}
