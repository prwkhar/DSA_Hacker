#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        if(root==nullptr)
        {
            return;
        }
       // Create a map to store the top view nodes
    map<int, int> top_view_map; // {horizontal_distance: node_data}

    // Queue for level order traversal, stores pair of node and its horizontal distance
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* node = temp.first;
        int hd = temp.second;

        // If this horizontal distance is not in the map, add it (first node encountered at this distance)
        if (top_view_map.find(hd) == top_view_map.end()) 
        {
            top_view_map[hd] = node->data;
        }

        // Enqueue left child with horizontal distance -1
        if (node->left != nullptr) {
            q.push({node->left, hd - 1});
        }

        // Enqueue right child with horizontal distance +1
        if (node->right != nullptr) {
            q.push({node->right, hd + 1});
        }
    }

    // Print the top view nodes from the map, sorted by horizontal distance
    for (auto it : top_view_map) {
        cout << it.second << " ";
    }
    cout << endl;}

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}
