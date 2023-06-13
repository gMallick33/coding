class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        int answer = 0;
        map<vector<int>, int> myMap;
        for(auto row: grid){
            myMap[row]++;
        }
        for(int i = 0; i < n; i++){
            vector<int> columnList = {};
            for(int j = 0; j < n; j++){
                columnList.push_back(grid[j][i]);
            }
            answer += myMap[columnList];
        }
        return answer;
    }
};