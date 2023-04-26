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
    struct node_values{
    int bst_sum;
    int max_val;
    int min_val;
};
node_values func(TreeNode *root, int &maxi){
    if(root == NULL){
         struct node_values temp = {0, INT_MIN, INT_MAX};
         return temp;
    }
    else{
        auto left = func(root->left, maxi);
        auto right = func(root->right, maxi);
        
        if(left.max_val < root->val && root->val < right.min_val){
            struct node_values temp = {root->val + left.bst_sum + right.bst_sum, max(root->val, right.max_val), min(root->val, left.min_val)};
            maxi = max(maxi, temp.bst_sum);
            return temp;
        }
        else{
            struct node_values temp = {max(left.bst_sum, right.bst_sum), INT_MAX, INT_MIN};
            return temp;
        }
    }
    
}
    int maxSumBST(TreeNode* root) {
        int maxi = 0;
        func(root, maxi);
        return maxi;
    }
};