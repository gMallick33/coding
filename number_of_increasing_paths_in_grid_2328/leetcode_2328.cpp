class Solution {
public:
    int mod = 1e9 + 7;
    int drow[4] = {1, 0, -1, 0};
    int dcol[4] = {0, 1, 0, -1};

    bool isValid(int i, int j, vector<vector<int>> &grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return false;
        else return true;
    }

    int dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(dp[row][col] != -1) return dp[row][col];
        int ans = 1;
        for(int i = 0; i < 4; i++){
            int newRow = row + drow[i];
            int newCol = col + dcol[i];

            if(isValid(newRow, newCol, grid) && grid[newRow][newCol] > grid[row][col]){
                ans = (ans % mod + dfs(newRow, newCol, grid, dp) % mod) % mod;
            }
        }
        return dp[row][col] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long count = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                count = (count % mod + dfs(i, j, grid, dp) % mod) % mod;
            }
        }
        return count;
    }
};