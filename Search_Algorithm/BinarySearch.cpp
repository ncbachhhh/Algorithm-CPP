//
// Created by nguye on 10/17/2025.
//
// Binary Search

#include <iostream>
#include <vector>

using namespace std;

void inputArray(vector<int>& arr) {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter Array Elements in sorted order: ";
    for ( int i = 0; i < n; i++ ) {
        int element;
        cout << "Enter element number " << i + 1 << ": ";
        cin >> element;
        arr.emplace_back(element);
    }
}

int binarySearch(const vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;
    while ( start <= end ) {
        int mid = (start + end) / 2;
        if ( arr[mid] == key ) {
            return mid;
        }
        else if ( arr[mid] < key ) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}


int main() {
    vector<int> arr;
    inputArray(arr);
    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;
    int result = binarySearch(arr, key);
    if ( result != -1 ) {
        cout << "Element found at index " << result << endl;
    }
    else {
        cout << "Element not found" << endl;
    }
}