#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>  // for rand()
using namespace std;
using namespace chrono;

// Brute force average
void brute(const vector<int>& a, vector<double>& x1) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += a[j];
        }
        x1.push_back((double)sum / (i + 1));
    }
}

// Optimized average using prefix sum
void optimal(const vector<int>& a, vector<double>& x2) {
    int n = a.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        x2.push_back((double)sum / (i + 1));
    }
}

int main() {
    cout << "n,BruteTime(ns),OptimizedTime(ns)\n";  // CSV header

    const int REPEATS = 100;  // repeat to get better timing

    for (int n = 100; n <= 2000; n += 100) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 100;  // Random values 0-99
        }

        long long totalBrute = 0, totalOptimal = 0;

        for (int r = 0; r < REPEATS; r++) {
            vector<double> x1, x2;

            auto start1 = high_resolution_clock::now();
            brute(a, x1);
            auto stop1 = high_resolution_clock::now();
            totalBrute += duration_cast<nanoseconds>(stop1 - start1).count();

            auto start2 = high_resolution_clock::now();
            optimal(a, x2);
            auto stop2 = high_resolution_clock::now();
            totalOptimal += duration_cast<nanoseconds>(stop2 - start2).count();

            // Prevent optimization
            volatile double use1 = x1.back();
            volatile double use2 = x2.back();
        }

        cout << n << "," << (totalBrute / REPEATS) << "," << (totalOptimal / REPEATS) << "\n";
    }

    return 0;
}
