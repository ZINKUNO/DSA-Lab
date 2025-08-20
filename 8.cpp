#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int item) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == item)
            return mid;
        else if (arr[mid] < item)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
}

int findInsertPosition(vector<int> &arr, int item) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < item)
            left = mid + 1;
        else
            right = mid;
    }
    return left; 
}

void insertSorted(vector<int> &arr, int item) {
    int pos = findInsertPosition(arr, item);
    arr.push_back(0); // make space for one more element
    for (int i = arr.size() - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = item;
}

void deleteItem(vector<int> &arr, int item) {
    int index = binarySearch(arr, item);
    if (index != -1) {
        for (int i = index; i < arr.size() - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr.pop_back(); // remove last element after shifting
    }
}

int main() {
    int n, item;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter item to search: ";
    cin >> item;

    int index = binarySearch(arr, item);

    if (index != -1) {
        cout << "Item found at index " << index << ". Deleting...\n";
        deleteItem(arr, item);
    } else {
        cout << "Item not found. Inserting...\n";
        insertSorted(arr, item);
    }

    cout << "Updated array: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}
