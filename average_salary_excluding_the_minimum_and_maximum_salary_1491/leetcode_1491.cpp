class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        double answer = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            answer += salary[i];
            if(salary[i] < mini) mini = salary[i];
            if(salary[i] > maxi) maxi = salary[i];
        }
        answer = answer - mini - maxi;
        return answer / (n - 2);
    }
};