// Partition functions - divide the array according to predefined conditions
// check if vector partitioned
// get the partition point
// create partition of the vector
// create partition saving elements order
// create partition by copying elements into two vectors

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// source vectors
vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};


// match function: isVowel
bool isVowel(char ch) {
    return binary_search(vowels.begin(), vowels.end(), ch);
}

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
    vector<char> v1(26, ' ');
    vector<char> v2(26, ' ');
    vector<char> v3(26, ' ');
    vector<char> v4;
    vector<char> v5;
    // print header
    cout << "*****************************************************" << endl;
    cout << "Demonstarte partition functions" << endl;
    // demonstrate partition fonction
    cout << "demonstrate partition fonction\n";
    // create lowercase letters array
    generate(v1.begin(), v1.end(), genLower);
    printVector("Source vector v1", v1);
    if(is_partitioned(v1.begin(), v1.end(), isVowel))
        cout << "v1 partitioned\n";
    else
        cout << "v1 not partitioned\n";
    // partition the array
    partition(v1.begin(), v1.end(), isVowel);
    printVector("v1 after partition", v1);
    if(is_partitioned(v1.begin(), v1.end(), isVowel))
        cout << "v1 partitioned\n";
    else
        cout << "v1 not partitioned\n";
    // find partition point
    auto itr1 = partition_point(v1.begin(), v1.end(), isVowel);
    cout << "Partition point is: " << *itr1 << endl;
    cout << endl;
    // demonstrate stable partition function
    cout << "demonstrate stable partition fonction\n";
    // create uppercase letters array
    generate(v2.begin(), v2.end(), genUpper);
    printVector("Source vector v2", v2);
    if(is_partitioned(v2.begin(), v2.end(), isVowel))
        cout << "v2 partitioned\n";
    else
        cout << "v2 not partitioned\n";
    // partition the array
    stable_partition(v2.begin(), v2.end(), isVowel);
    printVector("v2 after partition", v2);
    if(is_partitioned(v2.begin(), v2.end(), isVowel))
        cout << "v2 partitioned\n";
    else
        cout << "v2 not partitioned\n";
    cout << endl;
    // demonstrate partition copy function
    cout << "demonstrate partition copy function\n";
    generate(v3.begin(), v3.end(), genLower);
    printVector("Source vector v3", v3);
    if(is_partitioned(v3.begin(), v3.end(), isVowel))
        cout << "v3 partitioned\n";
    else
        cout << "v3 not partitioned\n";
    partition_copy(v3.begin(), v3.end(), inserter(v4, v4.end()), inserter(v5, v5.end()), isVowel);
    printVector("Vowels pratitioned to v4", v4);
    printVector("Not vowels partitioned to v5", v5);
    cout << endl;
    return 0;
}