#include <bits/stdc++.h>
using namespace std;

string preToInfix(string exp) {
    string ans="";
    stack<string>st;
    
    for(int i=exp.size()-1; i>=0; i--){
        if(isalpha(exp[i]) || isdigit(exp[i])){
            st.push(string(1, exp[i]));
        }else{
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string ns = "(" + a + exp[i] + b + ")";
            st.push(ns);
        }
    }
    return st.top();
}

int main(){
    string a = "*+pq-mn";
    cout << preToInfix(a);
}