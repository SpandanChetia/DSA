#include<bits/stdc++.h>
using namespace std;

class Stack {
public:
    queue<int>q;
    Stack() {
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        for(int i=1; i<size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(empty()){
            return -1;
        }
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.pop();
}