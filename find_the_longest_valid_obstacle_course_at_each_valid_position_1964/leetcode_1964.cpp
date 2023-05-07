class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> dp(n + 1, INT_MAX), answer;
        for(auto elem: obstacles){
            int idx = upper_bound(dp.begin(), dp.end(), elem) - dp.begin();
            dp[idx] = elem;
            answer.push_back(idx + 1);
        }
        return answer;
    }
};