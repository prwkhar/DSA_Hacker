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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        std::vector<TreeNode*> nodes;
        preorderTraversal(root, nodes);
        
        for (size_t i = 1; i < nodes.size(); ++i) {
            TreeNode* prev = nodes[i - 1];
            TreeNode* curr = nodes[i];
            prev->left = nullptr;
            prev->right = curr;
        }
    }

private:
    void preorderTraversal(TreeNode* node, std::vector<TreeNode*>& nodes) 
    {
        if (!node) return;
        nodes.push_back(node);
        preorderTraversal(node->left, nodes);
        preorderTraversal(node->right, nodes);
    }

// Helper function to print the flattened tree as a linked list
void printLinkedList(TreeNode* root) {
    while (root) {
        std::cout << root->val << " -> ";
        root = root->right;
    }
    std::cout << "None" << std::endl;
}
};