// practice on finding minimum and maximum elements
// in this pracctice creating a structure for list element
// the task is finding minimum and maximum element of this structure
// it can be usefull to truck elements of more complex structs
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>      // to generate random numbers

using namespace::std;

// basic structure of list elements
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

// function to determine the bigger node
// if a < b returns true
// otherwise return false
// used for both max_element() and min_element()
bool lt(Node* a, Node* b) {
    return (*a).data < (*b).data;
}

// custom search function to find maximum element using fuction 'lt'
// input parameter is reference to the vector
Node* findMax(const vector<Node*>& vc) {
    Node* mx = vc[0];
    for(Node* n: vc)
    {
        if(n->data > mx->data)
        {
            mx = n;
        }
    }
    return mx;
}

int main() {
    vector<Node*> vc;
    // create random list
    srand(time(0)); 
    for(int i=0; i<20; i++)
    {
        Node* n = new Node(rand());
        vc.push_back(n);
    }

    // print the nodes
    cout << "Following is the list of 20 nodes:\n";
    for(int i=0; i<20; i++)
    {
        cout << vc[i]->data << ", ";
    }
    cout << endl;

    // print maximum element
    auto mx = max_element(vc.begin(), vc.end(), lt);
    cout << "Max element: " << (*mx)->data << endl;

    // print minimum element
    auto mn = min_element(vc.begin(), vc.end(), lt);
    cout << "Min element: " << (*mn)->data << endl;

    // maximum element using custom function
    Node* myMx = findMax(vc);
    cout << "Max element using custom function: " << myMx->data << endl;

    // deleting nodest
    for (int i = 0; i < 20; i++)
    {
        delete vc[i];
    }
    
    return 0;
}