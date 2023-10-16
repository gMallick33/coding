class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1, 1};

        vector<int> currentRow = {1, 1};
        vector<int> nextRow;
        for(int i = 2; i <= rowIndex; i++){
            vector<int> nextRow = {1};
            int n = currentRow.size();
            for(int j = 0; j < n - 1; j++){
                nextRow.push_back(currentRow[j] + currentRow[j + 1]);
            }
            nextRow.push_back(1);
            currentRow = nextRow;
        }
        return currentRow;
    }
};