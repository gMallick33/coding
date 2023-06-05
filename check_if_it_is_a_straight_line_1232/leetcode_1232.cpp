class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2) return true;
        int n = coordinates.size();
        auto point1 = coordinates[0];
        auto point2 = coordinates[1];
        int x1 = point1[0];
        int y1 = point1[1];
        int x2 = point2[0];
        int y2 = point2[1];
        
        for(int i = 2; i < n; i++){
            if((y2 - y1) * (coordinates[i][0] - x1) == (coordinates[i][1] - y1) * (x2 - x1)) continue;
            else return false;
        }
        return true;
    }
};