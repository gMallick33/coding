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
    bool is_valid(TreeNode* root, long long low, long long high){
        if(root == NULL) return true;
        if(root->val >= high || root->val <= low) return false;
        return is_valid(root->left, low, root->val) && is_valid(root->right, root->val, high);
    }
    bool isValidBST(TreeNode* root) {
        return is_valid(root, LLONG_MIN, LLONG_MAX);
    }
};