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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        else{
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(isBalanced(root->left) && isBalanced(root->right)){
            int left_height = 1 + maxDepth(root->left);
            int right_height = 1 + maxDepth(root->right);
            if(abs(left_height - right_height) > 1) return false;
            else return true;
        }
        return false;
        
    }
};