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

int findDiameter(TreeNode* root, int&maxi){
    if(!root){
        return 0;
    }
    int l = findDiameter(root->left, maxi);
    int r = findDiameter(root->right, maxi);
    maxi = max(maxi, l+r);
    return max(l, r) + 1;
}

int main(){
    TreeNode* root = NULL;
    root = addNode(root, 10);

    root = addNode(root, 5);
    root = addNode(root, 6);
    root = addNode(root, 7);
    root = addNode(root, 8);
    root = addNode(root, 11);

    int diameter = 0;
    findDiameter(root, diameter);
    cout << diameter << " ";
}