class Solution {
public:
    
    long long countOperationsToEmptyArray(vector<int>& nums) {
        map<int, int> myMap;
        int n = nums.size();
        for(int i = 0; i < n; i++) myMap[nums[i]] = i;
        sort(nums.begin(), nums.end());
        long long ops = 0;
        for(int i = 1; i < n; i++){
            if(myMap[nums[i]] < myMap[nums[i - 1]]) ops += n - i;
        }
        ops += n;
        return ops;
    }
};