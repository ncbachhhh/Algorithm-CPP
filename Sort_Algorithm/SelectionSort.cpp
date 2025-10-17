//
// Created by nguye on 10/16/2025.
//
// Selection Sort

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

int findMinIndex(vector<int>& arr, int startIndex) {
    int n = arr.size();
    int minIndex = startIndex;
    for ( int i = startIndex; i < n; i++ ) {
        if ( arr[i] < arr[minIndex] ) {
            minIndex = i;
        }
    }
    return minIndex;
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    cout << "Initial array: ";
    for ( int i = 0; i < n; i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for ( int i = 0; i < n - 1; i++ ) {
        int minIndex = findMinIndex(arr, i);
        swap(arr[i], arr[minIndex]);
        cout << "Step " << i + 1 << ": ";
        for ( int k = 0; k < n; k++ ) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr;
    inputArray(arr);
    int n = arr.size();
    selectionSort(arr);
    cout << "Sorted array: ";
    for ( int i = 0; i < n; i++ ) {
        cout << arr[i] << " ";
    }
    return 0;
}
