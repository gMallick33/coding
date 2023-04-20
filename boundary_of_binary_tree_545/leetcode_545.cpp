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
    bool is_leaf(TreeNode* root){
        if(root == NULL) return true;
        if(root->left || root->right) return false;
        return true;
    }
    void add_leaf(TreeNode* root, vector<int> &answer){
        if(root == NULL) return;
        if(!is_leaf(root)){
            if(root->left){
                add_leaf(root->left, answer);
            }
            if(root->right){
                add_leaf(root->right, answer);
            }
        }
        else answer.push_back(root->val);
    }
    void add_right_boundary(TreeNode* root, stack<int> &mystack){
        if(root == NULL) return;
        else{
            if(!is_leaf(root)){
                mystack.push(root->val);
            }
            if(root->right){
                add_right_boundary(root->right, mystack);
            }
            else{
                add_right_boundary(root->left, mystack);
            }
        }
    }
    void add_left_boundary(TreeNode* root, vector<int> &answer){
        if(root == NULL) return;
        else{
            if(!is_leaf(root)){
                answer.push_back(root->val);
                if(root->left){
                    add_left_boundary(root->left, answer);
                }
                else{
                    add_left_boundary(root->right, answer);
                }
            }
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> answer;
        stack<int> mystack;
        if(root == NULL) return answer;
        else{
            if(root->left){
                add_left_boundary(root, answer);
            }
            else{
                if(!is_leaf(root)){
                    answer.push_back(root->val);
                }
            }
            add_leaf(root, answer);
            if(root->right){
                add_right_boundary(root->right, mystack);
            }
            while(!mystack.empty()){
                int top = mystack.top();
                mystack.pop();
                answer.push_back(top);
            }
        }
        return answer;
    }
};