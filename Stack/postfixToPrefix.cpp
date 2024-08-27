#include <bits/stdc++.h>
using namespace std;

string postToPre(string exp) {
    string ans="";
    stack<string>st;
    
    for(auto& c: exp){
        if(isalpha(c) || isdigit(c)){
            st.push(string(1, c));
        }else{
            string a="", b="";
            if(!st.empty()){
                a = st.top();
                st.pop();
            }
            if(!st.empty()){
                b = st.top();
                st.pop();
            }
            string ns = c + b + a;
            st.push(ns);
        }
    }
    return st.top();
}

int main(){
    string a = "ab+cd-*-";
    cout << postToPre(a);
}