#include <bits/stdc++.h>
using namespace std;

// Heaps are Complete Binary Trees
// Height = logn where n is no. of nodes

// MAX Heap Implementation

class MaxHeap {
    private:
    vector<int>heap;

    void heapify_up(int index){
        if(index==0){
            return;
        }
        int parent = (index-1)/2;
        if(heap[index] > heap[parent]){
            swap(heap[index],  heap[parent]);
            heapify_up(parent);
        }
    }

    void heapify_down(int index){
        int leftchild = 2*index+1;
        int rightchild = 2*index+2;
        int largest = index;
        if(largest<heap.size() && heap[largest]<heap[leftchild]){
            largest = leftchild;
        }

        if(largest<heap.size() && heap[largest]<heap[rightchild]){
            largest = rightchild;
        }

        if(largest!=index){
            swap(heap[largest], heap[index]);
            heapify_down(largest);
        }
    }
    public:
    MaxHeap(){}

    void push(int value){
        heap.push_back(value);
        heapify_up(heap.size()-1);
    }

    void pop(){
        if(heap.empty()){
            throw runtime_error("MaxHeap is Empty!!");
        }
        swap(heap[0], heap.back());
        heap.pop_back();
        heapify_down(0);
    }

    int top() const {
        if (heap.empty()) {
            throw runtime_error("MaxHeap is Empty!!");
        }
        return heap.front();
    }

    bool empty() const{
        return heap.size()==0;
    }

    size_t size() const{
        return heap.size();
    }
};

int main(){
    MaxHeap pq;
    pq.push(10);
    pq.push(30);
    pq.push(40);
    pq.push(-5);

    pq.pop();
    pq.pop();

    cout << pq.top() << " ";
}