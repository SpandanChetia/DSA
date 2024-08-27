#include<bits/stdc++.h>
using namespace std;

class MinHeap {
    public:
    vector<int>heap;

    void heapify_down(int index){
        int n = heap.size();
        int left = 2*index+1;
        int right = 2*index+2;

        int smallest = index;
        if (left<n && heap[left]<heap[smallest]){
            smallest = left;
        }
        if (right<n && heap[right]<heap[smallest]){
            smallest = right;
        }
        if (smallest != index){
            swap(heap[index], heap[smallest]);
            heapify_down(smallest);
        }
    }

    void heapify_up(int index){
        int parent = (index-1)/2;
        if (parent >= 0 && heap[parent] > heap[index]){
            swap(heap[index], heap[parent]);
            heapify_up(parent);
        }
    }

    void buildHeap(vector<int>&nums){
        heap = nums;
        for (int i = (nums.size()/2)-1; i >= 0; i--){
            heapify_down(i);
        }
    }

    void push(int value){
        heap.push_back(value);
        heapify_up(heap.size() - 1);
    }

    void pop(){
        if (heap.empty()){
            throw runtime_error("Heap is empty");
        }
        swap(heap[0], heap.back());
        heap.pop_back();
        heapify_down(0); 
    }

    int top(){
        if (heap.empty()){
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }
    size_t size(){
        return heap.size();
    }
};

class QuickS {
    public:
    int partition(int left, int right, vector<int>&nums){
        int p = nums[right];
        int l = left; 
        for (int i = left; i < right; i++){
            if (nums[i] <= p){
                swap(nums[l], nums[i]);
                l++;
            }
        }
        swap(nums[l], nums[right]);
        return l;
    }
    int quickSelect(int left, int right, int k, vector<int>&nums){
        if (left == right){
            return nums[left];
        }

        int pivot = partition(left, right, nums);

        if (pivot == k){
            return nums[pivot];
        } else if (pivot > k){
            return quickSelect(left, pivot - 1, k, nums);
        }
        return quickSelect(pivot + 1, right, k, nums); 
    }
};

class Kthlargest{
    public:
    int sortingMethod(vector<int>&nums, int k){
        sort(nums.rbegin(), nums.rend());
        return nums[k - 1];
    }

    int simplePQMethod(vector<int>&nums, int k){
        priority_queue<int>pq;
        for (auto& n : nums){
            pq.push(n);
        }
        for (int i = 0; i < k - 1; i++){
            pq.pop();
        }
        return pq.top();
    }

    int optimizedPQMethod(vector<int>&nums, int k){
        priority_queue<int, vector<int>, greater<int>>pq;
        for (int i = 0; i < nums.size(); i++){
            if (pq.size() < k){
                pq.push(nums[i]);
            } else if (pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

    int betterPQMethod(vector<int>&nums, int k){
        int n = nums.size();
        make_heap(nums.begin(), nums.end(), greater<int>());

        for (int i = 0; i < n - k; i++){
            pop_heap(nums.begin(), nums.end(), greater<int>());
            nums.pop_back();
        }
        return nums.front();

        MinHeap h;
        h.buildHeap(nums);

        for (int i = 0; i<n-k; i++){
            h.pop();
        }
        return h.top();
    }

    int quickSelectMethod(vector<int>&nums, int k){
        int n = nums.size();
        k = n - k; 
        QuickS q;
        return q.quickSelect(0, n-1, k, nums);
    }
};
                // 5 DIFFERENT METHODS
int main(){
    Kthlargest sol;
    vector<int>nums = {2, 3, 4, 5, 1, 6};
    int k = 4;
    cout << sol.betterPQMethod(nums, k);
}
