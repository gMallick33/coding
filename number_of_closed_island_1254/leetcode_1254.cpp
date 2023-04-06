class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &visited){
        if(visited[row][col]) return;
        int n = mat.size();
        int m = mat[0].size();
        visited[row][col] = 1;
        queue<pair<int, int>> myqueue;
        myqueue.push(make_pair(row, col));
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        while(!myqueue.empty()){
            auto front_elem = myqueue.front();
            int row_elem = front_elem.first;
            int col_elem = front_elem.second;
            myqueue.pop();
            
            for(int i = 0; i < 4; i++){
                int new_row = row_elem + drow[i];
                int new_col = col_elem + dcol[i];
                if(new_row < n && new_row >= 0 && new_col < m && new_col >= 0 && !visited[new_row][new_col] && mat[new_row][new_col] == 0){
                    visited[new_row][new_col] = 1;
                    myqueue.push(make_pair(new_row, new_col));
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            if(!visited[i][0] && grid[i][0] == 0)
                bfs(i, 0, grid, visited);
        }
        for(int j = 1; j < m; j++){
            if(!visited[n - 1][j] && grid[n - 1][j] == 0)
                bfs(n - 1, j, grid, visited);
        }
        for(int i = n - 2; i >=0; i--){
            if(!visited[i][m - 1] && grid[i][m - 1] == 0)
                bfs(i, m - 1, grid, visited);
        }
        for(int j = m - 2; j >= 1; j--){
            if(!visited[0][j] && grid[0][j] == 0)
                bfs(0, j, grid, visited);
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int answer = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 0){
                    answer++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return answer;
    }
};