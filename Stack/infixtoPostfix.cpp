#include <bits/stdc++.h>
using namespace std;

string infixToPostfix(string s) {
    string ans = "";
    unordered_map<char, int> p;
    p['^'] = 3;
    p['*'] = 2;
    p['/'] = 2;
    p['+'] = 1;
    p['-'] = 1;
    p['('] = 0;

    stack<char> st;
    
    for (auto& c : s) {
        if (isalpha(c) || isdigit(c)) {
            ans += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); 
        } else {
            while (!st.empty() && p[c] <= p[st.top()]) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main(){
    string a = "a+b-c*(d-e)";
    cout << infixToPostfix(a);
}