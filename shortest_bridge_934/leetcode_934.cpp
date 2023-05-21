class Solution {
public:
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, -1, 0, 1};
    vector<pair<int, int>> firstIsland, secondIsland;
    void mark(int row, int col, vector<vector<int>>& grid){
        grid[row][col] = 2;
        firstIsland.push_back(make_pair(row, col));
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < 4; i++){
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1){
                mark(newRow, newCol, grid);
            }
        }

    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool markingDone = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    mark(i, j, grid);
                    markingDone = true;
                    break;
                }
            }
            if(markingDone) break;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) secondIsland.push_back(make_pair(i, j));
            }
        }
        int mini = 1e9;
        for(int i = 0; i < firstIsland.size(); i++){
            for(int j = 0; j < secondIsland.size(); j++){
                mini = min(mini, abs(firstIsland[i].first - secondIsland[j].first) + abs(firstIsland[i].second - secondIsland[j].second));
            }
        }
        return mini - 1;
    }
};