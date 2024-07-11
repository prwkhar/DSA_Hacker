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
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inor(root,v);
        return ifsorted(v);
    }
    void inor(TreeNode* root,vector<int>& v)
    {
        if(root==nullptr)
        return;
        inor(root->left,v);
        v.push_back(root->val);
        inor(root->right,v);
    }
    bool ifsorted(vector<int>& v)
    {
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>=v[i+1])
            return false;
        }
        return true;
    }
};