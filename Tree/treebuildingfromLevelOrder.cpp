#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

TreeNode* BuildTree(vector<int>&levelOrder){
    if(levelOrder.empty()){
        return NULL;
    }
    int i=1;
    queue<TreeNode*>q;
    TreeNode* root = new TreeNode(levelOrder[0]);
    q.push(root);

    int size = levelOrder.size();
    while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();

        if(i<size){
            cur->left = new TreeNode(levelOrder[i]);
            q.push(cur->left);
        }
        i++;

        if(i<size){
            cur->right = new TreeNode(levelOrder[i]);
            q.push(cur->right);
        }
        i++;
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

int main(){
    vector<int>levelOrder = {5, 10, 15, 20, 25, 35, 45};
    TreeNode* root = NULL;
    root = BuildTree(levelOrder);
    inorder(root);

    cin.get();
}