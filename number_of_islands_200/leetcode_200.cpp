class Solution {
public:
    int drow[4] = {0, 1, 0, -1};
    int dcol[4] = {1, 0, -1, 0};
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited){
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int, int>> bfs_queue;
        bfs_queue.push({row, col});
        while(!bfs_queue.empty()){
            auto front = bfs_queue.front();
            int front_row = front.first;
            int front_col = front.second;
            bfs_queue.pop();
            for(int i = 0; i < 4; i++){
                int new_row = front_row + drow[i];
                int new_col = front_col + dcol[i];
                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !visited[new_row][new_col] && grid[new_row][new_col] == '1'){
                    visited[new_row][new_col] = 1;
                    bfs_queue.push({new_row, new_col});
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    island++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return island;
    }
};