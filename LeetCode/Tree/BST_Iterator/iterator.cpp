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
class BSTIterator {
private: stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode* val=myStack.top();
        myStack.pop();
        pushall(val->right);
        return val->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
    void pushall(TreeNode* root)
    {
            while(root)
            {
                myStack.push(root);
                root=root->left;
            }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */