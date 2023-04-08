/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* func(Node* node, map<Node*, Node*> &mymap){
        if(!node) return NULL;
        else{
            Node* copy = new Node(node->val);
            mymap[node] = copy;
            queue<Node*> bfs_queue;
            bfs_queue.push(node);
            while(!bfs_queue.empty()){
                auto front = bfs_queue.front();
                bfs_queue.pop();
                for(auto neigh: front->neighbors){
                    if(mymap.find(neigh) == mymap.end()){
                        Node* temp = new Node(neigh->val);
                        mymap[neigh] = temp;
                        bfs_queue.push(neigh);
                    }
                    mymap[front]->neighbors.push_back(mymap[neigh]);
                    
                }
            }
            return copy;
        }
    }
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mymap;
        return func(node, mymap);
    }
};