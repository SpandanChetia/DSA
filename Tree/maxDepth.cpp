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

int findHeight(TreeNode* root){   // RECURSIVE
    if(!root){
        return 0;
    }
    int l = findHeight(root->left);
    int r = findHeight(root->right);

    return 1 + max(l,r);
}

int findHeightI(TreeNode* root){  // ITERATIVE
    int ans=0;
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        while(size--){
            TreeNode* c = q.front(); q.pop();
            if(c->left) q.push(c->left);
            if(c->right) q.push(c->right);
        }
        ans++;
    }
    return ans;
}
int main(){
    vector<int>levelOrder = {5, 10, 15, 20, 25, 35, 45};
    TreeNode* root = NULL;
    root = BuildTree(levelOrder);
    //inorder(root);

    int maxDepth = findHeightI(root);
    cout << maxDepth;
}