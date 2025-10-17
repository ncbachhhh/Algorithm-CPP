//
// Created by ADMIN on 17/10/2025.
//
// Merge Sort

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

void mergeSort(vector<int>& arr) {
    int n = arr.size();
    if ( n < 2 ) {
        return;
    }
    int mid = n/2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    mergeSort(left);
    mergeSort(right);

    int i = 0, j = 0, k = 0;
    while ( i < left.size() && j < right.size() ) {
        if (left[i] > right[j]) {
            arr[k++] = right[j++];
        } else {
            arr[k++] = left[i++];
        }
    }

    // cleanup phần còn lại của mảng còn lại
    while ( i < left.size() ) {
        arr[k++] = left[i++];
    }
    while ( j < right.size() ) {
        arr[k++] = right[j++];
    }
}

int main() {
    vector<int> arr;
    inputArray(arr);
    int n = arr.size();
    mergeSort(arr);
    cout << "Sorted array: ";
    for ( int i = 0; i < n; i++ ) {
        cout << arr[i] << " ";
    }
    return 0;
}