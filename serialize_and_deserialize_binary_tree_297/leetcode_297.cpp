/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string answer = "";
        queue<TreeNode*> bfs_queue;
        bfs_queue.push(root);
        while(!bfs_queue.empty()){
            auto front = bfs_queue.front();
            bfs_queue.pop();
            if(front == NULL) answer += "#,";
            else{
                int num = front->val;
                answer += to_string(num);
                answer += ',';
                bfs_queue.push(front->left);
                bfs_queue.push(front->right);
            }
        }
        return answer;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> bfs_queue;
        bfs_queue.push(root);
        while(!bfs_queue.empty()){
            auto front = bfs_queue.front();
            bfs_queue.pop();
            getline(s, str, ',');
            if(str == "#"){
                front->left = NULL;
            }
            else{
                front->left = new TreeNode(stoi(str));
                bfs_queue.push(front->left);
            }
            getline(s, str, ',');
            if(str == "#"){
                front->right = NULL;
            }
            else{
                front->right = new TreeNode(stoi(str));
                bfs_queue.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));