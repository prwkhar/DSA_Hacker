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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, postorderIndex, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeHelper(const vector<int>& inorder, const vector<int>& postorder, int& postorderIndex, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int curr = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(curr);
        if (start == end) {
            return root;
        }

        int pos = search(inorder, curr, start, end);
        root->right = buildTreeHelper(inorder, postorder, postorderIndex, pos + 1, end);
        root->left = buildTreeHelper(inorder, postorder, postorderIndex, start, pos - 1);

        return root;
    }
};