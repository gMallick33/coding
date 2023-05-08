class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += mat[i][i];
        }
        for(int i = 0; i < n; i++){
            sum += mat[i][n - i - 1];
        }
        int centralElement = 0;
        if(n % 2 == 1) centralElement = mat[n / 2][n / 2];
        sum -= centralElement;
        return sum;
    }
};