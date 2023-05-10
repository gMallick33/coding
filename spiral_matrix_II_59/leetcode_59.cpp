class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int start_row = 0;
        int start_col = 0;
        int end_row = n - 1;
        int end_col = n - 1;

        int row = start_row;
        int col = start_col;
        
        int elem = 1;
        while(elem <= n * n){
            while(col <= end_col && elem <= n * n){
                matrix[row][col] = elem;
                elem++;
                col++;
            }
            col = end_col;
            row++;
            while(row <= end_row && elem <= n * n){
                matrix[row][col] = elem;
                elem++;
                row++;
            }
            
            row = end_row;
            col--;
            while(col >= start_col && elem <= n * n){
                matrix[row][col] = elem;
                elem++;
                col--;
            }
            col = start_col;
            row--;
            while(row > start_row && elem <= n * n){
                matrix[row][col] = elem;
                elem++;
                row--;
            }

            start_row++;
            end_row--;
            start_col++;
            end_col--;
            row = start_row;
            col = start_col;
        }
        return matrix;
    }
};