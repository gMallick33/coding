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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return build(ind, preorder, INT_MAX);
    }
    TreeNode* build(int &ind, vector<int> &preorder, int upper_bound){
        if(ind == preorder.size() || preorder[ind] >= upper_bound) return NULL;
        TreeNode* node = new TreeNode(preorder[ind++]);
        node->left = build(ind, preorder, node->val);
        node->right = build(ind, preorder, upper_bound);
        return node;
    }
};