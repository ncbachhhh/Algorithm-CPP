//
// Created by nguye on 10/16/2025.
//

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

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    cout << "Initial array: ";
    for ( int i = 0; i < n; i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for ( int i = 1; i < n; i++ ) {
        int key = arr[i];
        int j = i - 1;
        while ( j >= 0 && arr[j] > key ) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        cout << "Step " << i << ": ";
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
    insertionSort(arr);
    cout << "Sorted array: ";
    for ( int i = 0; i < n; i++ ) {
        cout << arr[i] << " ";
    }
    return 0;
}