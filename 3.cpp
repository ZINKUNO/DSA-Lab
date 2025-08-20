#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>::iterator binary_find(vector<int>& v, int key)
{
    auto it = lower_bound(v.begin(), v.end(), key);
    if (it != v.end() && *it == key)
        return it;
    return v.end();
}

int main()
{
    vector<int> v;
    int n, item;

    /* ---------- read initial sorted data ---------- */
    cout << "How many elements? ";
    cin >> n;
    if (n < 0) return 0;

    cout << "Enter " << n << " integers in ascending order: ";
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        v.push_back(x);
    }

    /* ---------- read the ITEM to search ---------- */
    cout << "Enter ITEM to search/insert/delete: ";
    cin >> item;

    /* ---------- binary search ---------- */
    auto it = binary_find(v, item);

    if (it != v.end())                  // FOUND → erase
    {
        cout << "ITEM found at index "
             << distance(v.begin(), it)
             << " → deleting...\n";
        v.erase(it);
    }
    else                               // NOT FOUND → insert
    {
        auto pos = lower_bound(v.begin(), v.end(), item);
        cout << "ITEM not found → inserting at index "
             << distance(v.begin(), pos) << "...\n";
        v.insert(pos, item);
    }

    /* ---------- display result ---------- */
    cout << "Array now (" << v.size() << " elements): ";
    for (int x : v) cout << x << ' ';
    cout << '\n';
}