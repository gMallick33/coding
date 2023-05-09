class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int start_row = 0;
        int start_col = 0;
        int end_row = n - 1;
        int end_col = m - 1;

        vector<int> answer;
        int row = start_row;
        int col = start_col;
        int totalElem = 0;
        while(totalElem < n * m){
            while(col <= end_col && totalElem < n * m){
                answer.push_back(matrix[row][col]);
                totalElem++;
                col++;
            }
            col = end_col;
    //         start_row++;
            row++;
            while(row <= end_row && totalElem < n * m){
                answer.push_back(matrix[row][col]);
                totalElem++;
                row++;
            }
            
    //         start_col++;
            row = end_row;
            col--;
            while(col >= start_col && totalElem < n * m){
                answer.push_back(matrix[row][col]);
                totalElem++;
                col--;
            }
            col = start_col;
            row--;
            while(row > start_row && totalElem < n * m){
                answer.push_back(matrix[row][col]);
                totalElem++;
                row--;
            }

            start_row++;
            end_row--;
            start_col++;
            end_col--;
            row = start_row;
            col = start_col;
        }
        return answer;
    }
};