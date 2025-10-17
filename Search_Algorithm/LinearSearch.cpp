//
// Created by ADMIN on 17/10/2025.
//
// Linear Search

#include <iostream>
#include <vector>

using namespace std;

void inputArray(vector<int>& arr) {
    int n;
    cout << "Enter Array Elements: ";
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        int element;
        cout << "Enter elements number " << i + 1 << ": ";
        cin >> element;
        arr.emplace_back(element);
    }
}

int linearSearch(vector<int> arr, int key) {
    for ( int i = 0; i < arr.size(); i++ ) {
        if ( arr[i] == key ) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> arr;
    inputArray(arr);
    int n = arr.size();
    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;
    int result = linearSearch(arr, key);
    if ( result != -1 ) {
        cout << "Element found at index" << result << endl;
    }
    else {
        cout << "Element not found" << endl;
    }
    return 0;
}