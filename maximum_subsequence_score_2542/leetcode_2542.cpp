class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> myVec;
        int n = nums1.size();
        for(int i = 0; i < n; i++){
            myVec.push_back({nums2[i], nums1[i]});
        }
        sort(myVec.rbegin(), myVec.rend());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int i = 0;
        long long ans = 0;
        long long currSum = 0;
        while(i < n){
            minHeap.push(myVec[i].second);
            currSum += myVec[i].second;
            if(i >= k - 1){
                ans = max(ans, (long long)currSum * myVec[i].first);
                currSum -= minHeap.top();
                minHeap.pop();
            }
            i++;
        }
        return ans;
    }
};