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

int maxW(TreeNode* root) {
    if (!root) {
        return 0;
    }
    
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int ans = 0;
    
    while (!q.empty()) {
        int size = q.size();
        int left = q.front().second; 
        int first, last;
        
        for (int i = 0; i < size; i++) {
            int curPos = q.front().second-left; 
            TreeNode* node = q.front().first;
            q.pop();
            
            if (i==0) first = curPos;  
            if (i==size-1) last = curPos; 
            
            if (node->left) {
                q.push({node->left, 2*curPos+1});
            }
            if (node->right) {
                q.push({node->right, 2*curPos+2});
            }
        }
        
        ans = max(ans, last-first+1);
    }
    
    return ans;
}

int main(){
    TreeNode* root = NULL;
    root = addNode(root, 1);
    TreeNode* l = new TreeNode(3);
    root->left = l;
    TreeNode* r = new TreeNode(2);
    root->right = r;
    TreeNode* r1 = new TreeNode(5);
    TreeNode* r2 = new TreeNode(3);
    TreeNode* r3 = new TreeNode(9);

    l->left = r1; l->right = r2;
    r->right = r3;


    int maxiWidth = maxW(root);
    cout << maxiWidth << " ";
}
