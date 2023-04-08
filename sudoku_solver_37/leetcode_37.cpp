class Solution {
public:
    bool func(vector<vector<char>> &board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(is_valid(c, i, j, board)){
                            board[i][j] = c;
                            if(func(board)){
                                return true;
                            }
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool is_valid(char c, int row, int col, vector<vector<char>> &board){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == c)
                return false;
            if(board[i][col] == c)
                return false;
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        func(board);
    }
};