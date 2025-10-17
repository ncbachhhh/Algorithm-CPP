//
// Created by nguye on 10/16/2025.
//
// Bubble Sort

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

void bubbleSort(vector<int>& arr) {
    int temp = 0;
    int n = arr.size();
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n-i-1; j++ ) {
            if ( arr[j] > arr[j + 1] ) {
                cout << "Step " << ++temp << ": ";
                swap( arr[j], arr[j + 1]);
                for ( int k = 0; k < n; k++ ) {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }
    }
}

int main() {
    vector<int> array;
    inputArray(array);
    int n = array.size();
    bubbleSort(array);
    cout << "Sorted array: ";
    for ( int i = 0; i < n; i++ ) {
        cout << array[i] << " ";
    }
    return 0;
}