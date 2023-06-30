class Solution {
public:
    int getMinOps(int idx, int prev, vector<int>& arr1, vector<int>& arr2, map<pair<int, int>, int> &dp){
        if(idx == arr1.size()) return 0;
        if(dp.find({idx, prev}) != dp.end()) return dp[{idx, prev}];
        int ans = 1e9;
        int uBound = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if(arr1[idx] > prev) ans = min(ans, getMinOps(idx + 1, arr1[idx], arr1, arr2, dp));
        if(uBound < arr2.size()) ans = min(ans, getMinOps(idx + 1, arr2[uBound], arr1, arr2, dp) + 1);
        return dp[{idx, prev}] = ans;

    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int> dp;
        int ans = getMinOps(0, INT_MIN, arr1, arr2, dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};