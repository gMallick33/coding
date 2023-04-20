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
    TreeNode* build(int start, int end, int &pindex, vector<int> &preorder, map<int, int> &inorder_node_map){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[pindex]);
        pindex++;
        if(start == end) return root;
        int iindex = inorder_node_map[root->val];
        
        TreeNode* left = build(start, iindex - 1, pindex, preorder, inorder_node_map);
        TreeNode* right = build(iindex + 1, end, pindex, preorder, inorder_node_map);
        root->left = left;
        root->right = right;
        return root;

    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pindex = 0;
        int start = 0;
        int end = inorder.size() - 1;
        map<int, int> mymap;
        for(int i = 0; i < inorder.size(); i++){
            mymap[inorder[i]] = i;
        }

        return build(start, end, pindex, preorder, mymap);
    }
};