class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = 0;
        int right_max = 0;
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int answer = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                left_max = max(left_max, height[left]);
                answer += (left_max - height[left]);
                left++;
            }
            else{
                right_max = max(right_max, height[right]);
                answer += (right_max - height[right]);
                right--;
            }
        }
        return answer;
    }
};