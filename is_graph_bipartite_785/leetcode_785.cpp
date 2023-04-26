class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            int col = 0;
            if(color[i] == -1){
                color[i] = col;
                queue<int> bfs_queue;
                bfs_queue.push(i);
                while(!bfs_queue.empty()){
                    int front = bfs_queue.front();
                    bfs_queue.pop();
                    int neigh_col = (color[front] + 1) % 2;
                    for(auto neigh: graph[front]){
                        if(color[neigh] == -1){
                            color[neigh] = neigh_col;
                            bfs_queue.push(neigh);
                        }
                        else{
                            if(color[neigh] == neigh_col) continue;
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};