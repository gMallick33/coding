class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int me1 = INT_MAX;
        int me2 = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == me1)
                count1++;
            else if(nums[i] == me2)
                count2++;
            else if(count1 == 0){
                count1++;
                me1 = nums[i];
            }
            else if(count2 == 0){
                count2++;
                me2 = nums[i];
            }
            
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == me1)
                count1++;
            else if(nums[i] == me2)
                count2++;
            else
                continue;
        }
        
        vector<int> answer;
        if(count1 > nums.size() / 3)
            answer.push_back(me1);
        if(count2 > nums.size() / 3)
            answer.push_back(me2);
        return answer;
    }
};