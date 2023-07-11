/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, map<TreeNode*, TreeNode*> &parent_nodes){
        if(root == NULL) return;
        if(root->left){
            parent_nodes[root->left] = root;
            traverse(root->left, parent_nodes);
        }
        if(root->right){
            parent_nodes[root->right] = root;
            traverse(root->right, parent_nodes);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent_nodes;
        map<TreeNode*, bool> visited;
        vector<int> answer;
        traverse(root, parent_nodes);
        queue<pair<TreeNode*, int>> bfs_queue;
        bfs_queue.push({target, 0});
        visited[target] = true;
        while(!bfs_queue.empty()){
            auto front_elem = bfs_queue.front();
            bfs_queue.pop();
            auto front_node = front_elem.first;
            auto distance = front_elem.second;
            if(distance == k){
                answer.push_back(front_node->val);
                continue;
            }
            if(front_node->left && visited.find(front_node->left) == visited.end()){
                visited[front_node->left] = true;
                bfs_queue.push({front_node->left, distance + 1});
            }
            if(front_node->right && visited.find(front_node->right) == visited.end()){
                visited[front_node->right] = true;
                bfs_queue.push({front_node->right, distance + 1});
            }
            if(parent_nodes.find(front_node) != parent_nodes.end() && visited.find(parent_nodes[front_node]) == visited.end()){
                visited[parent_nodes[front_node]] = true;
                bfs_queue.push({parent_nodes[front_node], distance + 1});
            }
        }
        return answer;
    }
};