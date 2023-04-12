class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(n == 1) return;
        for(int i = 0; i < n; i++){
            for(int j = i; j < m; j++){
                if(i == j) continue;
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};