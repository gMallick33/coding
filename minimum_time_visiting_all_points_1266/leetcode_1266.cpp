class Solution {
public:
    int chebyshevDist(vector<int> &point1, vector<int> &point2) {
        return max(abs(point1[0] - point2[0]), abs(point1[1] - point2[1]));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        vector<int> prev = points[0];
        int answer = 0;
        for(auto point: points) {
            answer += chebyshevDist(point, prev);
            prev = point;
        }
        return answer;
    }
};