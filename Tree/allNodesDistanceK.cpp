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

void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent){
    queue<TreeNode*>q;

    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
}

vector<int>distanceK(TreeNode* root, TreeNode* target, int k){
    if(!root){
        return {};
    }
    queue<TreeNode*>q;
    unordered_map<TreeNode*, TreeNode*>parent;
    findParent(root, parent);
    unordered_map<TreeNode*, int>vis;
    q.push(target);
    int count=0;
    vis[target] = true;
    while(!q.empty()){
        int size = q.size();
        if(count==k){
            break;
        }
        for(int i=0; i<size; i++){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left && !vis[curr->left]){
                q.push(curr->left);
                vis[curr->left] = true;
            }

            if(curr->right && !vis[curr->right]){
                vis[curr->right] = true;
                q.push(curr->right);
            }

            if(parent[curr] && !vis[parent[curr]]){
                vis[parent[curr]] = true;
                q.push(parent[curr]);
            }
        }
        count++;
    }
    vector<int>ans;
    while(!q.empty()){
        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
}
int main(){
    TreeNode* root = NULL;
    root = addNode(root, 3);
    TreeNode* l = new TreeNode(5);
    root->left = l;
    TreeNode* r = new TreeNode(1);
    root->right = r;
    TreeNode* l1 = new TreeNode(6);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l3 = new TreeNode(7);
    TreeNode* l4 = new TreeNode(4);
    TreeNode* r1 = new TreeNode(0);
    TreeNode* r2 = new TreeNode(8);
    
    l->left = l1;
    l->right = l2;
    l2->left = l3;
    l2->right = l4;
    r->left = r1;
    r->right = r2;

    int k = 2;
    vector<int>ans = distanceK(root, l, k);   // Here l = node 5
    for(auto& a : ans){
        cout << a << " ";
    }
}
