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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(!root) return answer;
        queue<TreeNode*> bfs_queue;
        bfs_queue.push(root);
        while(!bfs_queue.empty()){
            int size = bfs_queue.size();
            vector<int> answer_partial;
            for(int i = 0; i < size; i++){
                auto front_elem = bfs_queue.front();
                bfs_queue.pop();
                answer_partial.push_back(front_elem->val);
                if(front_elem->left) bfs_queue.push(front_elem->left);
                if(front_elem->right) bfs_queue.push(front_elem->right);
            }
            answer.push_back(answer_partial);
        }
        return answer;
    }
};