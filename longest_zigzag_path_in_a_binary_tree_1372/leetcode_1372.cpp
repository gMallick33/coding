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
    int maxi_path = 0;
    void func(TreeNode* root, string prev_path, int path_length){
        if(!root) return;
        maxi_path = max(maxi_path, path_length);
        if(prev_path == "left"){
            func(root->right, "right", 1 + path_length);
            func(root->left, "left", 1);
        }
        else{
            func(root->left, "left", 1 + path_length);
            func(root->right, "right", 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        
        func(root, "left", 0);
        func(root, "right", 0);
        return maxi_path;
    }
};