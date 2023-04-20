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
    void connect(Node* child_left, Node* child_right){
        if(!child_left || !child_right) return;
        child_left->next = child_right;
        child_right->next = NULL;
        connect(child_left->left, child_left->right);
        connect(child_left->right, child_right->left);
        connect(child_right->left, child_right->right);
    }
    Node* connect(Node* root) {
        if(!root) return root;
        connect(root->left, root->right);
        return root;
    }
};