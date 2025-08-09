#include <iostream>
#include <vector>
#include <chrono>  // For timing

using namespace std;
using namespace chrono;  // So you can write 'high_resolution_clock' etc. without full prefix

// Brute Force Method
void brute(vector<int>& a, vector<double>& x1) {
    int n = a.size();
    cout << "Brute Force: ";
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += a[j];
        }
        x1.push_back((double)sum / (i + 1));
    }
    for (int i = 0; i < n; i++) {
        cout << x1[i] << " ";
    }
    cout << endl;
}

// Optimized Method
void optimal(vector<int>& a, vector<double>& x2) {
    int n = a.size();
    int sum = 0;
    cout << "Optimized:   ";
    for (int i = 0; i < n; i++) {
        sum += a[i];
        x2.push_back((double)sum / (i + 1));
    }
    for (int i = 0; i < n; i++) {
        cout << x2[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter Number of Elements in array: ";
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter " << i + 1 << " element: ";
        cin >> a[i];
    }

    vector<double> x1, x2;

    // Timing Brute Force
    auto start1 = high_resolution_clock::now();
    brute(a, x1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Brute Force Time: " << duration1.count() << " microseconds" << endl;

    // Timing Optimized
    auto start2 = high_resolution_clock::now();
    optimal(a, x2);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Optimized Time:   " << duration2.count() << " microseconds" << endl;

    return 0;
}
