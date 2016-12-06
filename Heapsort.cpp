#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void percolateDown(int arr[], int position, int n) {
    int largest = position;
    if ( position * 2 + 1 < n && arr[ position ] < arr[ position * 2 + 1 ] ) {
        largest = position * 2 + 1; 
    }
    if ( position * 2 + 2 < n && arr[ largest ] < arr[ position * 2 + 2 ] ) {
        largest = position * 2 + 2;
    }
    if ( largest != position ) {
        swap(arr[ position ], arr[ largest ]);
        percolateDown(arr , largest , n);
    }

}

void buildHeap (int arr[], int n) {
    for (int i = (n - 1) / 2; i >= 0; i--) {
        percolateDown(arr, i, n);
    }
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n-1);
    for(int i = n - 1; i >= 1;) {
        swap(arr[0], arr[i]);
        i--;
        percolateDown(arr, 0, i);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}


int main()
{
    int insertArray[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(insertArray) / sizeof(int);

    cout << "Before heapSort : \n";
    printArray(insertArray, n);

    heapSort(insertArray, n);
    cout << "\n\nAfter heapSort : \n";
    printArray(insertArray, n);

    return 0;
}
