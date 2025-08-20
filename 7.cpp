#include <iostream>
using namespace std;

int binarySearchOrInsertPos(int arr[], int size, int item) {
    int left = 0, right = size; 
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < item)
            left = mid + 1;
        else
            right = mid;
    }
    return left; 
}

void insertAtPos(int arr[], int &size, int pos, int item) {
    for (int i = size; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = item;
    size++;
}

void deleteAtPos(int arr[], int &size, int pos) {
    for (int i = pos; i < size - 1; i++)
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

    int pos = binarySearchOrInsertPos(arr, n, item);

    if (pos < n && arr[pos] == item) {
        cout << "Item found at index " << pos << ". Deleting..."<<endl;
        deleteAtPos(arr, n, pos);
    } else {
        cout << "Item not found. Inserting..."<<endl;
        insertAtPos(arr, n, pos, item);
    }

    cout << "Updated array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
