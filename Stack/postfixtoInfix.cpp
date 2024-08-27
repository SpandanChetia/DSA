#include <bits/stdc++.h>
using namespace std;

string postToInfix(string exp) {
    string ans="";
    stack<string>st;
    
    for(auto& c : exp){
        if(isalpha(c) || isdigit(c)){
            st.push(string(1, c));
        }else{
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string ns = "(" + b + c + a + ")";
            st.push(ns);
        }
    }
    return st.top();
}

int main(){
    string a = "ab+cde-*-";
    cout << postToInfix(a);
}