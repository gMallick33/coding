class Solution {
public:
    static bool compare(pair<int, int> &a, pair<int, int> &b){
        return a.first < b.first;
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> rangePairVec;
        for(int i = 0; i < n + 1; i++){
            rangePairVec.push_back({i - ranges[i], i + ranges[i]});
        }
        sort(rangePairVec.begin(), rangePairVec.end(), compare);
        int tapCount = 0;
        int idx = 0;
        int left = 0;
        int right = 0;
        while(right < n){
            for(idx; idx < n + 1 && rangePairVec[idx].first <= left; idx++){
                right = max(right, rangePairVec[idx].second);
            }
            if(left == right) return -1;
            left = right;
            tapCount++;
        }
        return tapCount;
    }
};