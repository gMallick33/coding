class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> mystack_left;
        for(int i = 0; i < heights.size(); i++){
            if(mystack_left.empty() || heights[i] >= heights[mystack_left.top()]){
                mystack_left.push(i);
            }
            else{
                while(!mystack_left.empty() && heights[i] < heights[mystack_left.top()]){
                    int top = mystack_left.top();
                    left[top] = i;
                    mystack_left.pop();
                }
                mystack_left.push(i);
            }
        }
        while(!mystack_left.empty()){
            int top = mystack_left.top();
            left[top] = -1;
            mystack_left.pop();
        }
        
        stack<int> mystack_right;
        for(int i = n - 1; i >= 0; i--){
            if(mystack_right.empty() || heights[i] >= heights[mystack_right.top()]){
                mystack_right.push(i);
            }
            while(!mystack_right.empty() && heights[i] < heights[mystack_right.top()]){
                int top = mystack_right.top();
                right[top] = i;
                mystack_right.pop();
            }
            mystack_right.push(i);
        }
        while(!mystack_right.empty()){
            int top = mystack_right.top();
            right[top] = -1;
            mystack_right.pop();
        }
        
        vector<int> temp;
        temp = left;
        left = right;
        right = temp;
        int max_area = 0;
        int total_area;
        for(int i = 0; i < n; i++){
            int left_area, right_area;
            if(left[i] == -1){
                left_area = heights[i] * (i);
            }
            else{
                left_area = heights[i] * (i - left[i] - 1);
            }
            if(right[i] == -1){
                right_area = heights[i] * (n - i);
            }
            else{
                right_area = heights[i] * (right[i] - i);
            }
            total_area = left_area + right_area;
            if(total_area > max_area){
                max_area = total_area;
            }
        }

        return max_area;
    }
};