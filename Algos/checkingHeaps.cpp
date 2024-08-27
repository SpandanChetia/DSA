#include<bits/stdc++.h>
using namespace std;

bool checkMinHeap(vector<int>&heap){
    int n = heap.size();
    for(int i=0; i<(n-2)/2; i++){
        if(2*i+1<n && heap[i]>heap[2*i+1]){
            return false;
        }
        if(2*i+2<n && heap[i]>heap[2*i+2]){
            return false;
        }
    }
    return true;
}

bool checkMaxHeap(vector<int>&heap){
    int n = heap.size();
    for(int i=0; i<(n-2)/2; i++){
        if(2*i+1<n && heap[i]<heap[2*i+1]){
            return false;
        }
        if(2*i+2<n && heap[i]<heap[2*i+2]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int>minheap = {1, 3, 5, 7, 9, 8, 10};
    vector<int>minheap2 = {10, 3, 5, 7, 9, 8, 1};
    cout << checkMinHeap(minheap2);
}