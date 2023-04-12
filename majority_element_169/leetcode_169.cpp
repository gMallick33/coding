class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_element = nums[0];
        int maj_element_freq = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == maj_element) maj_element_freq++;
            else{
                if(maj_element_freq == 0){
                    maj_element = nums[i];
                    maj_element_freq = 1;
                }
                else{
                    maj_element_freq--;
                }
            }
        }
        return maj_element;
    }
};