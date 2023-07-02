class Solution {
public:
    int ans = 0;
    void func(int idx, vector<int> &dp, vector<vector<int>>& requests, int count){
        if(idx == requests.size()){
            bool all0 = true;
            for(int i = 0; i < dp.size(); i++){
                if(dp[i] == 0) continue;
                else{
                    return;
                }
            }
            if(all0) ans = max(ans, count);
            return;
        }
        int from = requests[idx][0];
        int to = requests[idx][1];
        
        dp[from] -= 1;
        dp[to] += 1;
        func(idx + 1, dp, requests, count + 1);

        dp[from] += 1;
        dp[to] -= 1;
        func(idx + 1, dp, requests, count);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> dp(n, 0);
        func(0, dp, requests, 0);
        return ans;
    }
};