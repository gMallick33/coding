class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<int, int> myMap;
        for(int i = 0; i < n; i++){
            int val = 0;
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    val += (1 << j);
                }
            }
            if(val == 0) return {i};
            for(int j = 1; j <= 31; j++){
                if(((val & j) == 0) && myMap.count(j)) return {myMap[j], i};
            }
            myMap[val] = i;
        }
        return {};
    }
};