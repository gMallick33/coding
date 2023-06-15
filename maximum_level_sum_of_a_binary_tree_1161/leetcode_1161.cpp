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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 1;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        int maxi = INT_MIN;
        int maxiLevel = 0;
        int currentLevel = 0;
        while(!bfsQueue.empty()){
            int size = bfsQueue.size();
            currentLevel++;
            int currentSum = 0;
            for(int i = 0; i < size; i++){
                auto front = bfsQueue.front();
                bfsQueue.pop();
                currentSum += front->val;
                if(front->left) bfsQueue.push(front->left);
                if(front->right) bfsQueue.push(front->right);
            }
            if(maxi < currentSum){
                maxi = currentSum;
                maxiLevel = currentLevel;
            }
        }
        return maxiLevel;
    }
};