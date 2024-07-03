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
    bool sametree(TreeNode* r,TreeNode* q)
    {
        if(r==NULL&&q==NULL)
        {
            return true;
        }
        if(r!=NULL&&q!=NULL)
        {
        return(r->val==q->val&&sametree(r->right,q->right)&&sametree(r->left,q->left));
        }
        return false;
    }
    TreeNode* mirrorof(TreeNode* q)
    {
        if(q==NULL)
        {
            return NULL;
        }
        TreeNode* left=mirrorof(q->left);
        TreeNode* right=mirrorof(q->right);
        q->left=right;
        q->right=left;
        return q;
    }
    bool ismirror(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL&&root2==NULL)
        {
            return true;
        }
        if(root1&&root2&&root1->val==root2->val)
        {
           return( ismirror(root1->left,root2->right)&&ismirror(root1->right,root2->left));
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);
    }
};