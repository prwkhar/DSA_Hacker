/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneutil(Node* node,unordered_map<Node*,Node*>& mp)
    {
        Node* newnode=new Node(node->val);//cloned node
        mp[node]=newnode;
        for(auto n:node->neighbors)
        {
            if(mp.find(n)==mp.end())
            {
                //node is not present in the map
                Node* newnode1=new Node(n->val);
                mp[n]=newnode1;
                newnode->neighbors.push_back(mp[n]);
            }
            else
            {
                newnode->neighbors.push_back(mp[n]);
            }
        }
        return newnode;

    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
        return NULL;
        unordered_map<Node*,Node*> mp;
        return cloneutil(node,mp);
    }
};