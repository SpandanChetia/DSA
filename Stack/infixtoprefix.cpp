#include <bits/stdc++.h>
using namespace std;

string infixtoPre(string exp) {
    string ans = "";
    unordered_map<char, int> p;
    p['^'] = 3;
    p['*'] = 2;
    p['/'] = 2;
    p['+'] = 1;
    p['-'] = 1;
    
    // Reverse the infix expression
    reverse(exp.begin(), exp.end());
    
    stack<char> st;
    
    for (auto& c : exp) {
        if (isalpha(c) || isdigit(c)) {
            ans += c;
        } else if (c == ')') {
            st.push(c);
        } else if (c == '(') {
            while (!st.empty() && st.top() != ')') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && p[st.top()] > p[c]) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all remaining operators in the stack
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    
    // Reverse the result to get the final prefix expression
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string a = "a+b-c*(d-e)";
    cout << infixtoPre(a);
}
