class Solution {
public:
    
    void print_board(vector<vector<int>> board){
        int n = board.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    vector<string> create_answer(vector<vector<int>> board){
        int n = board.size();
        vector<string> answer_str;
        for(int i = 0; i < n; i++){
            string str = "";
            for(int j = 0; j < n; j++){
                if(board[i][j] == 0)
                    str += '.';
                else
                    str += 'Q';
            }
            answer_str.push_back(str);
        }
        return answer_str;
    }
    bool check_valid(int row, int col, vector<int> row_board, vector<int> diag, vector<int> other_diag){
        if(row_board[row] == 0 && diag[row + col] == 0 && other_diag[row_board.size() - 1 + col - row] == 0)
            return true;
        return false;
    }
    
    void func(int col, vector<vector<int>> &board, vector<int> &row_board, vector<int> &diag, vector<int> &other_diag, vector<vector<string>> &answer){
        if(col == board.size()){
            // print_board(board);
            vector<string> answer_str = create_answer(board);
            answer.push_back(answer_str);
            return;
        }
        for(int i = 0; i < board.size(); i++){
            if(check_valid(i, col, row_board, diag, other_diag)){
                row_board[i] = 1;
                diag[i + col] = 1;
                other_diag[board.size() - 1 + col - i] = 1;
                board[i][col] = 1;
                // print_board(board);
                func(col + 1, board, row_board, diag, other_diag, answer);
                row_board[i] = 0;
                diag[i + col] = 0;
                other_diag[board.size() - 1 + col - i] = 0;
                board[i][col] = 0;
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 1)
            return {{"Q"}};
        if(n == 2)
            return {};
        if(n == 3)
            return {};
        vector<int> row_board(n, 0);
        vector<int> diag(2 * n - 1, 0);
        vector<int> other_diag(2 * n - 1, 0);
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> answer;
        int col = 0;
        func(col, board, row_board, diag, other_diag, answer);
        return answer;
    }
};