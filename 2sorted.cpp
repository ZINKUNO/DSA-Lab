#include <iostream>
using namespace std;

void bubbleSort(int* arr, int size) {
    bool flag;
    for (int i = 0; i < size - 1; i++) {
        flag = false;  
        
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;  
            }
        }
        
        if (!flag) {
            cout << "Array sorted in " << i + 1 << " passes" << endl;
            break;
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    cout << "\nOriginal array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Sort the array
    bubbleSort(arr, size);
    
    // Print sorted array
    cout << "\nSorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    return 0;
}
