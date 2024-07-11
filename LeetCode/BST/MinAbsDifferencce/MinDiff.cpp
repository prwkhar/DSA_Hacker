#include <vector>
#include <climits>
#include <cstdlib>  // for abs()


class Solution  {
public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;
        inorderTraversal(root, prev, minDiff);
        return minDiff;
    }

private:
    void inorderTraversal(TreeNode* node, TreeNode*& prev, int& minDiff) {
        if (!node) return;
        
        inorderTraversal(node->left, prev, minDiff);
        
        if (prev) {
            int diff = node->val - prev->val;
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
        prev = node;
        
        inorderTraversal(node->right, prev, minDiff);
    }
};
