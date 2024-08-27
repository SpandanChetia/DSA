#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

TreeNode* addNode(TreeNode* root, int value) {
    if (!root) {
        return new TreeNode(value);
    }
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new TreeNode(value);
            return root;
        } else {
            q.push(temp->left);
        }
        if (!temp->right) {
            temp->right = new TreeNode(value);
            return root;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

void inorder(TreeNode* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void leftboundary(TreeNode* root, vector<int>&ans){
    if(!root || (!root->left && !root->right)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        leftboundary(root->left, ans);
    }
    else if(root->right){
        leftboundary(root->right, ans);
    }
}

void leaves(TreeNode* root, vector<int>&ans){
    if(!root){
        return;
    }
    leaves(root->left, ans);
    if(!root->left && !root->right){
        ans.push_back(root->data);
    }
    leaves(root->right, ans);
}

void rightboundary(TreeNode* root, stack<int>&st){
    if(!root || (!root->left && !root->right)){
        return;
    }
    st.push(root->data);
    if(root->right){
        rightboundary(root->right, st);
    }
    else if(root->left){
        rightboundary(root->left, st);
    }
}
int main(){
    TreeNode* root = NULL;
    root = addNode(root, 10);

    root = addNode(root, 5);
    root = addNode(root, 6);
    root = addNode(root, 7);
    root = addNode(root, 8);
    root = addNode(root, 11);

    // Boundary ORDER TRAVERSAL

    vector<int>ans;
    ans.push_back(root->data);
    leftboundary(root->left, ans);
    if(root->left || root->right) {
        leaves(root, ans);
    }
    stack<int>st;
    rightboundary(root->right, st);
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    for(auto& c : ans){
        cout << c << " ";
    }
    cin.get();
}