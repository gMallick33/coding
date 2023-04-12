class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        else if(numRows == 2) return {{1}, {1, 1}};
        else{
            vector<vector<int>> answer = {{1}, {1, 1}};
            for(int i = numRows - 2; i > 0; i--){
                vector<int> prev_row = answer.back();
                vector<int> current_row = {1};
                int n = prev_row.size();
                for(int j = 1; j < n; j++){
                    current_row.push_back(prev_row[j] + prev_row[j - 1]);
                }
                current_row.push_back(1);
                answer.push_back(current_row);
            }
            return answer;
        }
    }
};