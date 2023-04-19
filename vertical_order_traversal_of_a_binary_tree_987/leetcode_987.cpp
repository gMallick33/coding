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
    void traverse(int dist, int level, TreeNode* root, map<int, map<int, multiset<int>>> &nodes_by_distance){
        if(root == NULL) return;
        nodes_by_distance[dist][level].insert(root->val);
        traverse(dist - 1, level + 1, root->left, nodes_by_distance);
        traverse(dist + 1, level + 1, root->right, nodes_by_distance);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes_by_distance;
        vector<vector<int>> vertical_order;
        if(root == NULL) return vertical_order;
        int dist = 0;
        int level = 0;
        traverse(dist, level, root, nodes_by_distance);
        for(auto dist_pair: nodes_by_distance){
            auto level_pair = dist_pair.second;
            vector<int> nodes_at_level;
            for(auto set_pair: level_pair){
                auto nodes = set_pair.second;
                for(auto node: nodes){
                    nodes_at_level.push_back(node);
                }
            }
            vertical_order.push_back(nodes_at_level);
        }
        return vertical_order;
    }
};