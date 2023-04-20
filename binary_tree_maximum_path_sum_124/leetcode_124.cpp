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
    int func(TreeNode* root, int &max_path_sum){
        if(root == NULL) return 0;
        else{
            int left_path_sum = func(root->left, max_path_sum);
            int right_path_sum = func(root->right, max_path_sum);
            max_path_sum = max({max_path_sum, root->val + left_path_sum + right_path_sum, root->val + left_path_sum, root->val + right_path_sum, root->val});
            return max({root->val + left_path_sum, root->val + right_path_sum, root->val});

        }
    }
    int maxPathSum(TreeNode* root) {
        int max_path_sum = INT_MIN;
        func(root, max_path_sum);
        return max_path_sum;
    }
};