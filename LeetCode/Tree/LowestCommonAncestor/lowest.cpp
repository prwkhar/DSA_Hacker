/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        
        vector<TreeNode*> pp, qq;
        findPath(root, p, pp);
        findPath(root, q, qq);
        
        int i = 0;
        TreeNode* node = nullptr;
        while (i < pp.size() && i < qq.size() && pp[i] == qq[i]) {
            node = pp[i];
            i++;
        }
        return node;
    }

private:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;
        path.push_back(root);
        if (root == target) return true;
        
        if ((root->left && findPath(root->left, target, path)) ||
            (root->right && findPath(root->right, target, path))) {
            return true;
        }
        
        path.pop_back();
        return false;
    }
};