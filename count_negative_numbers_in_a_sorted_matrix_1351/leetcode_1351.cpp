class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int negIndex = m - 1;
        for(auto row: grid){
            while(negIndex >= 0 && row[negIndex] < 0) negIndex--;
            count += (m - negIndex - 1);

        }
        return count;
    }
};