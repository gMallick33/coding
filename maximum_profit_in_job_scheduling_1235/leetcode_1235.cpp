class Solution {
public:
    int func(int idx, vector<pair<pair<int, int>, int>> &timings_profit, vector<int> &startTime, vector<int> &dp){
        int n = timings_profit.size();
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
 
        int next_idx = lower_bound(startTime.begin(), startTime.end(), timings_profit[idx].first.second) - startTime.begin();
        int take = timings_profit[idx].second + func(next_idx, timings_profit, startTime, dp);
        int not_take = func(idx + 1, timings_profit, startTime, dp);
        return dp[idx] = max(take, not_take);
    }
    static bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
        if(a.first.first == b.first.first) return a.first.second < b.first.second;
        else return a.first.first < b.first.first;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int, int>, int>> timings_profit;
        int n = startTime.size();
        for(int i = 0; i < n; i++){
            timings_profit.push_back({{startTime[i], endTime[i]}, profit[i]});
        }
        sort(timings_profit.begin(), timings_profit.end(), comp);

        for(int i = 0; i < n; i++){
            startTime[i] = timings_profit[i].first.first;
        }
        vector<int> dp(n, -1);
        return func(0, timings_profit, startTime, dp);
    }
};