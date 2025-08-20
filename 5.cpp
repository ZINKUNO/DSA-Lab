#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

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

    // lower_bound returns the first position where 'item' could be inserted
    auto it = lower_bound(arr.begin(), arr.end(), item);

    if (it != arr.end() && *it == item) {
        cout << "Item found. Deleting...\n";
        arr.erase(it); // erase the element
    } else {
        cout << "Item not found. Inserting...\n";
        arr.insert(it, item); // insert in sorted order
    }

    cout << "Updated array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
