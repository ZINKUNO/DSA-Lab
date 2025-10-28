#include <iostream>
#include <vector>
using namespace std;

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

/* QUICK SORT */
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* MERGE SORT */
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* INSERTION SORT */
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* SELECTION SORT */
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
            swap(arr[i], arr[minIdx]);
    }
}

/* MAIN FUNCTION WITH SWITCH CALLS */
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int choice;

    cout << "Original Array: ";
    printArray(arr);

    cout << "\n=== Choose Sorting Algorithm ===" << endl;
    cout << "1. Quick Sort\n";
    cout << "2. Merge Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Selection Sort\n";
    cout << "Enter choice (1-4): ";
    cin >> choice;

    // Create a copy of the array for sorting
    vector<int> sortedArr = arr;

    // Use switch to call different sorting functions
    switch (choice) {
        case 1:
            cout << "\n[Using Quick Sort]\n";
            quickSort(sortedArr, 0, sortedArr.size() - 1);
            break;

        case 2:
            cout << "\n[Using Merge Sort]\n";
            mergeSort(sortedArr, 0, sortedArr.size() - 1);
            break;

        case 3:
            cout << "\n[Using Insertion Sort]\n";
            insertionSort(sortedArr);
            break;

        case 4:
            cout << "\n[Using Selection Sort]\n";
            selectionSort(sortedArr);
            break;

        default:
            cout << "\nInvalid choice! No sorting applied.\n";
            return 0;
    }

    cout << "Sorted Array: ";
    printArray(sortedArr);

    return 0;
}