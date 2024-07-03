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
int search(const vector<int>& inorder, int curr, int start, int end) {
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == curr) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        return buildTreeHelper(preorder, inorder, preorderIndex, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeHelper(const vector<int>& preorder, const vector<int>& inorder, int& preorderIndex, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int curr = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(curr);
        if (start == end) {
            return root;
        }

        int pos = search(inorder, curr, start, end);
        root->left = buildTreeHelper(preorder, inorder, preorderIndex, start, pos - 1);
        root->right = buildTreeHelper(preorder, inorder, preorderIndex, pos + 1, end);

        return root;
    }
};