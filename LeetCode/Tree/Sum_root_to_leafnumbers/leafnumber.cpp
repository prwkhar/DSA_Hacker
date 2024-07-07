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
    int sumleaf(TreeNode* root,int currsum)
    {
        if(!root)
        return 0;
        currsum=currsum*10+root->val;
        if(!root->left&&!root->right)
        {
            return currsum;
        }
        int left=sumleaf(root->left,currsum);
        int right=sumleaf(root->right,currsum);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        int su= sumleaf(root,0);
        return su;
    }
};