class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        if(n == 1) return intervals;
        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= answer.back()[1]) answer.back()[1] = max(answer.back()[1], intervals[i][1]);
            else answer.push_back(intervals[i]);
        }
        return answer;
    }
};