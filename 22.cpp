#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue {
private:
    vector<int> heap;

    // Restore heap property upwards
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Restore heap property downwards
    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Insert a new element into the priority queue
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Remove and return the maximum element
    int pop() {
        if (heap.empty()) {
            cout << "Priority queue is empty!" << endl;
            return -1; // or throw an exception
        }

        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heapifyDown(0);
        }

        return maxVal;
    }

    // Return the maximum element without removing it
    int top() {
        if (heap.empty()) {
            cout << "Priority queue is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    // Check if the queue is empty
    bool empty() {
        return heap.empty();
    }

    // Get current size of the queue
    int size() {
        return heap.size();
    }
};

// Example usage
int main() {
    MaxPriorityQueue pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(40);

    cout << "Max element: " << pq.top() << endl;  // 40

    cout << "Extracting max: " << pq.pop() << endl;  // 40
    cout << "New max: " << pq.top() << endl;         // 30

    cout << "Extracting elements: ";
    while (!pq.empty()) {
        cout << pq.pop() << " ";
    }
    cout << endl;

    return 0;
}