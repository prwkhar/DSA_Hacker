/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inor(root,v);
        return v[k-1];
    }
    void inor(TreeNode* root,vector<int>& v)
    {
        if(!root)
        return;
        inor(root->left,v);
        v.push_back(root->val);
        inor(root->right,v);
    }
};