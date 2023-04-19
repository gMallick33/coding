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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, long long>> queue_nodes;
        queue_nodes.push({root, 0});
        int maxi = 0;
        while(!queue_nodes.empty()){
            int size = queue_nodes.size();
            int min_ind = queue_nodes.front().second;
            int first, last;
            for(int i = 0; i < size; i++){
                auto front_elem = queue_nodes.front();
                auto current_node = front_elem.first;
                long long current_id = front_elem.second - min_ind;
                queue_nodes.pop();
                if(i == 0) first = current_id;
                if(i == size - 1) last = current_id;
                if(current_node->left) queue_nodes.push({current_node->left, 2*current_id + 1});
                if(current_node->right) queue_nodes.push({current_node->right, 2*current_id + 2});
            }
            maxi = max(maxi, last - first + 1);
        }
        return maxi;
    }
};