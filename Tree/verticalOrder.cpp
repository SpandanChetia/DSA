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

vector<vector<int>> verticalOrder(TreeNode* root){
    if(!root){
        return {{}};
    }
    queue<tuple<TreeNode*,int,int>>q;
    map<int, map<int, multiset<int>>>mp;
    q.push(make_tuple(root, 0, 0));  

    while(!q.empty()){
        auto node_tuple = q.front();
        TreeNode* node;
        int row, col;
        tie(node, row, col) = node_tuple; 
        mp[col][row].insert(node->data);
        q.pop();
        if(node->left){
            q.push(make_tuple(node->left, row+1, col-1));
        }
        if(node->right){
            q.push(make_tuple(node->right, row+1, col+1));
        }
    }
    vector<vector<int>> ans;
    for(auto& p : mp){ 
        vector<int> sub;
        for(auto& q : p.second){
            sub.insert(sub.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(sub);
    }
    return ans;
}

int main(){
    TreeNode* root = NULL;
    root = addNode(root, 3);
    TreeNode* l = new TreeNode(9);
    root->left = l;
    TreeNode* r = new TreeNode(20);
    root->right = r;
    TreeNode* r1 = new TreeNode(15);
    TreeNode* r2 = new TreeNode(7);

    r->left = r1; r->right = r2;

    vector<vector<int>>ans = verticalOrder(root);

    for(auto& k : ans){
        for(int i=0; i<k.size(); i++){
            cout << k[i] << " ";
        }
        cout << endl;
    }
}