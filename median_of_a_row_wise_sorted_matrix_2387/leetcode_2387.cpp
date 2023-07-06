class Solution {
public:
    int countSmallerThanMid(vector<int> &row, int mid){
        int l = 0, h = row.size() - 1;
        while (l <= h)
        {
            int md = (l + h) >> 1;
            if (row[md] <= mid)
            {
            l = md + 1;
            }
            else
            {
            h = md - 1;
            }
        }
        return l;
        }
    int matrixMedian(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int low = 1;
        int high = 1e6;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            int count  = 0;
            for(int i = 0; i < n; i++) count += countSmallerThanMid(grid[i], mid);
            
            if(count <= (n * m) / 2) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};