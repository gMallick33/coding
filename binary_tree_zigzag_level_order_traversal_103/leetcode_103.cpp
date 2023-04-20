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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> queue_nodes;
        queue_nodes.push(root);
        int left_to_right = true;
        while(!queue_nodes.empty()){
            int size = queue_nodes.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++){
                TreeNode* front_node = queue_nodes.front();
                queue_nodes.pop();
                if(left_to_right) level[i] = front_node->val;
                else level[size - 1 - i] = front_node->val;
                if(front_node->left) queue_nodes.push(front_node->left);
                if(front_node->right) queue_nodes.push(front_node->right);
            }
            left_to_right = !left_to_right;
            result.push_back(level);
        }
        return result;
    }
};