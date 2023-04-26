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
public:
    stack<TreeNode*> node_stack;
    bool reverse;
    BSTIterator(TreeNode* root, bool is_reverse) {
        reverse = is_reverse;
        push_all(root);
    }
    
    int next() {
        auto top = node_stack.top();
        node_stack.pop();
        if(!reverse) push_all(top->right);
        else push_all(top->left);
        return top->val;
    }
    
    bool hasNext() {
        return !node_stack.empty();
    }
    void push_all(TreeNode* root){
        if(!reverse){
            while(root != NULL){
            node_stack.push(root);
            root = root->left;
            }
        }
        else{
            while(root != NULL){
            node_stack.push(root);
            root = root->right;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator* bst_low = new BSTIterator(root, false);
        BSTIterator* bst_high = new BSTIterator(root, true);
        int start = bst_low->next();
        int end = bst_high->next();
        while(start < end){
            if(start + end == k) return true;
            else if(start + end < k) start = bst_low->next();
            else end = bst_high->next();
        }
        return false;
    }
};