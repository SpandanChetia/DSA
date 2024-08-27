#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    stack<int>s1, s2;
    Queue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()){
            return -1;
        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()){
            return -1;
        }
        return s2.top();
    }
    
    bool empty() {
        return s2.empty() && s1.empty();
    }
};
