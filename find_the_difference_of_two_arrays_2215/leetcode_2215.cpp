class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);
        unordered_set<int> setNums1(nums1.begin(), nums1.end());
        unordered_set<int> setNums2(nums2.begin(), nums2.end());

        for(auto elem: setNums1){
            if(setNums2.find(elem) == setNums2.end()) answer[0].push_back(elem);
        }
        for(auto elem: setNums2){
            if(setNums1.find(elem) == setNums1.end()) answer[1].push_back(elem);
        }
        return answer;
    }
};