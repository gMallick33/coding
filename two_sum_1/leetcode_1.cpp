class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mymap;
        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];
            if(mymap.find(comp) != mymap.end()){
                return {i, mymap[comp]};
            }
            else{
                mymap[nums[i]] = i;
            }
        }
        return {};
    }
};