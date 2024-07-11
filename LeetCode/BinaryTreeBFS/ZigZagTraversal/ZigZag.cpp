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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int c=1;
        while(!q.empty())
        {
            int s=q.size();
            vector<int> level;
            for(int i=0;i<s;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(c%2!=0)
                level.push_back(node->val);
                else
                level.insert(level.begin(),node->val);
                if(node->left!=nullptr)
                {
                    q.push(node->left);
                }
                if(node->right!=nullptr)
                {
                    q.push(node->right);
                }
            }
            c++;
            ans.push_back(level);
        }
        return ans;
    }
};