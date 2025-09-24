#include <iostream>
#include <vector>
using namespace std;

// merge two consecutive sorted sub-ranges [left, mid] and [mid+1, right]
void merge(vector<int>& a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = a[left + i];
    for (int j = 0; j < n2; ++j) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

// recursive merge-sort 
void mergeSort(vector<int>& a, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid size."<<endl;
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers:"<<endl;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:"<<endl;
    for (int val : arr)
        cout << val << ' ';
    cout << endl;

    return 0;
}