/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)
        return NULL;
        vector<vector<Node*>> ma;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<Node*> level;
            for(int i=0;i<size;i++)
            {
            Node* node=q.front();
            level.push_back(node);
            q.pop();
            if(node->left!=nullptr)
            q.push(node->left);
            if(node->right!=nullptr)
            q.push(node->right);
            }
            ma.push_back(level);
        }
        for(int i=0;i<ma.size();i++)
        {
            for(int j=0;j<ma[i].size();j++)
            {
                if(j==ma[i].size()-1)
                {
                    ma[i][j]->next=NULL;
                }
                else
                {
                    ma[i][j]->next=ma[i][j+1];
                }
            }
        }
        return root;
    }
};