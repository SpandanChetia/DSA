#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

TreeNode *addNode(TreeNode *root, int value)
{
    if (!root)
    {
        return new TreeNode(value);
    }
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (!temp->left)
        {
            temp->left = new TreeNode(value);
            return root;
        }
        else
        {
            q.push(temp->left);
        }
        if (!temp->right)
        {
            temp->right = new TreeNode(value);
            return root;
        }
        else
        {
            q.push(temp->right);
        }
    }
    return root;
}

void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

TreeNode *findtarget(TreeNode *root, int target)
{
    if (!root)
    {
        return NULL;
    }
    if (root->data == target)
    {
        return root;
    }
    TreeNode *left = findtarget(root->left, target);
    TreeNode *right = findtarget(root->right, target);

    if (!left && !right)
    {
        return NULL;
    }
    else if (left)
    {
        return left;
    }
    return right;
}
void findParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
}

int minTime(TreeNode *root, int target)
{
    TreeNode *t = findtarget(root, target);
    unordered_map<TreeNode *, TreeNode *> parent;
    findParent(root, parent);
    queue<pair<TreeNode *, int>> q;
    unordered_map<TreeNode *, int> vis;
    q.push({t, 0});
    vis[t] = true;
    int ans = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            TreeNode *curr = p.first;

            if (curr->left && !vis[curr->left])
            {
                q.push({curr->left, p.second + 1});
                ans = max(ans, p.second + 1);
                vis[curr->left] = true;
            }
            if (curr->right && !vis[curr->right])
            {
                q.push({curr->right, p.second + 1});
                ans = max(ans, p.second + 1);
                vis[curr->right] = true;
            }
            if (parent[curr] && !vis[parent[curr]])
            {
                q.push({parent[curr], p.second + 1});
                ans = max(ans, p.second + 1);
                vis[parent[curr]] = true;
            }
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = NULL;
    root = addNode(root, 3);
    TreeNode *l = new TreeNode(5);
    root->left = l;
    TreeNode *r = new TreeNode(1);
    root->right = r;
    TreeNode *l1 = new TreeNode(6);
    TreeNode *l2 = new TreeNode(2);
    TreeNode *l3 = new TreeNode(7);
    TreeNode *l4 = new TreeNode(4);
    TreeNode *r1 = new TreeNode(0);
    TreeNode *r2 = new TreeNode(8);

    l->left = l1;
    l->right = l2;
    l2->left = l3;
    l2->right = l4;
    r->left = r1;
    r->right = r2;

    int ans = minTime(root, 8); 
    cout << ans << " ";
}