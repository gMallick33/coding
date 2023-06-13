class Solution {
public:
    int func(int idx, string &s, map<string, int> &myMap, vector<int> &dp){
        int n = s.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int res = 1e9;
        for(int i = 1; i + idx <= n; i++){
            string temp = s.substr(idx, i);
            if(myMap.find(temp) != myMap.end()){
                res = min(res, func(idx + i, s, myMap, dp));
            }
        }
        res = min(res, 1 + func(idx + 1, s, myMap, dp));
        return dp[idx] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        map<string, int> myMap;
        vector<int> dp(n, -1);
        for(auto elem: dictionary) myMap[elem]++;
        return func(0, s, myMap, dp);
    }
};