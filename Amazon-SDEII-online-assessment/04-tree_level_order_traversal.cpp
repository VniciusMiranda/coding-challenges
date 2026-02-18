//https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
#include <bits/stdc++.h>	

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

    void levelOrder(Node * root) {
        if (!root) return;
        
        queue<Node*> control_queue;
        control_queue.push(root);
        
        while(!control_queue.empty()) 
        {
            Node* current = control_queue.front();
            control_queue.pop();
            
            cout << current->data << " ";
            if (current->left)
            {
                control_queue.push(current->left);
            }
            if (current->right)
            {
                control_queue.push(current->right);
            }
        }
    }
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
	myTree.levelOrder(root);
    return 0;
}
