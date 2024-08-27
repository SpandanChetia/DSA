#include <bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int* arr;
    int capacity;
    int rear=-1;
    int front=0;
    int sz=0;

    Queue(int maxi){
        arr = new int[maxi];
        capacity = maxi;
    }

    ~Queue(){
        delete[] arr;
    }

    void push(int x){
        if(isFull()){
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear+1)%capacity;
        arr[rear] = x;
        sz++;
    }

    int pop(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int ans = arr[front];
        front = (front+1)%capacity;
        sz--;
        return ans;
    }
    
    int peek(){
        return arr[front];
    }
    
    bool isFull(){
        return sz==capacity;
    }

    bool isEmpty(){
        return sz==0;
    }

    int size(){
        return sz;
    }
};

int main(){
    Queue q(100);

    q.push(10);
    cout << q.pop() << " ";
    q.push(40);
    cout << q.pop() << " ";
    q.push(50);
    q.push(60);
    cout << q.size() << " ";

}