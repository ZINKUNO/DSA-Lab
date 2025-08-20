#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int item) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == item)
            return mid;
        else if (arr[mid] < item)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}

void insertSorted(int arr[], int &size, int item) {
    int i = size - 1;
    while (i >= 0 && arr[i] > item) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = item;
    size++;
}
void deleteItem(int arr[], int &size, int index) {
    for (int i = index; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
}

int main() {
    int arr[100]; 
    int n, item;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter item to search: ";
    cin >> item;

    int index = binarySearch(arr, n, item);

    if (index != -1) {
        cout << "Item found at index " << index << ". Deleting...\n";
        deleteItem(arr, n, index);
    } else {
        cout << "Item not found. Inserting...\n";
        insertSorted(arr, n, item);
    }

    cout << "Updated array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
