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

vector<vector<int>> zigzag(TreeNode* root){
    if(!root){
        return {{}};
    }
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    char dir = 'L';
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>subset(size);
        int index;
        for(int i=0; i<size; i++){
            TreeNode* c = q.front();
            q.pop();
            if(dir=='L'){
                index = i;
            }else{
                index = size-i-1;
            }

            subset[index] = c->data;
            if(c->left){
                q.push(c->left);
            }
            if(c->right){
                q.push(c->right);
            }
        }
        dir = (dir=='L' ? 'R' : 'L');
        ans.push_back(subset);
    }
    return ans;
}

int main(){
    TreeNode* root = NULL;
    root = addNode(root, 10);

    root = addNode(root, 5);
    root = addNode(root, 6);
    root = addNode(root, 7);
    root = addNode(root, 8);
    root = addNode(root, 11);

    vector<vector<int>> ans = zigzag(root);
    
    for(auto& v : ans){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}