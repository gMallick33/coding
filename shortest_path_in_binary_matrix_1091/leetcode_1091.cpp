class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        if(n == 1) return 1;
        queue<pair<pair<int, int>, int>> bfsQueue;
        bfsQueue.push({{0, 0}, 1});
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        vector<pair<int,int>>neighbours = {{0,1}, {0,-1}, {1,0}, {-1,0},
                                               {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        while(!bfsQueue.empty()){
            auto elem =  bfsQueue.front();
            int row = elem.first.first;
            int col = elem.first.second;
            int len = elem.second;
            if(row == n - 1 && col == n - 1) return len;
            bfsQueue.pop();
            for(auto neigh: neighbours){
                int newRow = row + neigh.first;
                int newCol = col + neigh.second;
                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < n && grid[newRow][newCol] == 0 && !visited[newRow][newCol]){
                    bfsQueue.push({{newRow, newCol}, len + 1});
                    visited[newRow][newCol] = 1;
                }
            }
        }
        return  -1;
    }
};