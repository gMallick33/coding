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
    void traverse(TreeNode* root, vector<int> &myvec){
        if(!root) return;
        traverse(root->left, myvec);
        traverse(root->right, myvec);
        myvec.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> myvec;
        traverse(root, myvec);
        return myvec;
    }
};