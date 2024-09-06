// practice of sorting algorithm
// sort vector dirct (from minimum to maximum)
// sort vector reverse (from maximum to minimum)
// special sort (using dedicated function)
// custom sort by using merge-sort algorithm

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// assisting function to print the vector
void print(vector<pair<int, int>> v, string title) {
    cout << title << ": ";
    for(auto p : v)
    {
        cout << p.first << " - " << p.second << ", ";
    }
    cout << "\n\n";
}

// assisting function to print the vector
void print(vector<int> v, string title) {
    cout << title << ": ";
    for(auto p : v)
    {
        cout << p << ", ";
    }
    cout << "\n\n";
}

// function for special sorting
// receives 2 elements
// when first greater than second returns true
bool mySort(pair<int, int> p1, pair<int, int> p2) {
    // main sorting is is done by first element
    // when first elements equals, second element conuts (bigger first)
    if(p1.first == p2.first)
    {
        return p1.second > p2.second;
    }
    else
    {
        return p1.first < p2.first;
    }
}

// self implementation of merge-sort algorithm
// merge used for merging two sorted array
void merge(vector<int>& arr, int l, int m, int r)
{
    // prepare left side temporary array
    int lSize = m - l + 1;
    int arrL[lSize];
    for(int i=0; i<lSize; i++)
    {
        arrL[i] = arr[l+i];
    }
    
    // prepare right side temporary array
    int rSize = r - m;
    int arrR[rSize];
    for(int j=0; j<rSize; j++)
    {
        arrR[j] = arr[m+1+j];
    }
         
    // start merge
    int i = 0;
    int j = 0;
    int k = l;
    while(i<lSize && j<rSize)
    {
        if(arrL[i] <= arrR[j])
        {
            arr[k] = arrL[i];
            i++;    
        }
        else
        {
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }
        
    // complete elements from left side
    while(i<lSize)
    {
        arr[k] = arrL[i];
        i++;
        k++;
    }
        
    // complete elements from right side
    while(j<rSize)
    {
        arr[k] = arrR[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r)
{
    //code here
    if(l<r)
    {
        int m = (r+l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// main function demonstrating sort opetions
int main() {
    vector<pair<int, int>> v = {{5,3}, {3,8}, {9,11}, {98, -4}, {5,2}, {5,4}};
    vector<int> v1 = {9, 2, 4, 6, 8, 9, 5, 98, 55, 43, 56};
    vector<int> v2 = {9, 2, 4, 6, 8, 9, 5, 98, 55, 43, 56};

    // print source array
    print(v1, "source of int array");

    // sort accending
    sort(v1.begin(), v1.end());
    print(v1, "accending sort of the array");

    // sort accending using custom mergesort fuction
    mergeSort(v2, 0, v2.size()-1);
    print(v2, "Custom sort function");

    // sort decending (used for integers only)
    sort(v1.begin(), v1.end(), greater<int>());
    print(v1, "decending sort of the array");

    // reverse the array
    reverse(v1.begin(), v1.end());
    print(v1, "int array reversed");

    // print source pair array
    print(v, "source of pair array");

    // custom sort
    sort(v.begin(), v.end(), mySort);
    print(v, "custom sort of the array");

    // reverse the array
    reverse(v.begin(), v.end());
    print(v, "pair array reversed");

}