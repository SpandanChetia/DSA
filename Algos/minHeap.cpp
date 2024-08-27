#include <bits/stdc++.h>
using namespace std;

// Heaps are Complete Binary Trees
// Height = logn where n is no. of nodes

// MAX Heap Implementation

class MinHeap {
private:
    vector<int> heap;

    void heapify_up(int index) {
        if (index == 0) {
            return;
        }
        int parent = (index-1)/2;
        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapify_up(parent);
        }
    }

    void heapify_down(int index) {
        int leftchild = 2 * index + 1;
        int rightchild = 2 * index + 2;
        int smallest = index;

        if (leftchild < heap.size() && heap[leftchild] < heap[smallest]) {
            smallest = leftchild;
        }

        if (rightchild <heap.size() && heap[rightchild] < heap[smallest]) {
            smallest = rightchild;
        }

        if (smallest != index) {
            swap(heap[smallest], heap[index]);
            heapify_down(smallest);
        }
    }

public:
    MinHeap() {}

    void push(int value) {
        heap.push_back(value);
        heapify_up(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            throw runtime_error("MinHeap is Empty!!");
        }
        swap(heap[0], heap.back());
        heap.pop_back();
        heapify_down(0);
    }

    int top() const {
        if (heap.empty()) {
            throw runtime_error("MinHeap is Empty!!");
        }
        return heap[0];
    }

    bool empty() const {
        return heap.size() == 0;
    }

    size_t size() const {
        return heap.size();
    }
};

int main() {
    MinHeap pq;
    pq.push(10);
    pq.push(30);
    pq.push(40);
    pq.push(-5);

    pq.pop(); 
    pq.pop();

    cout << pq.top() << " "; 
}