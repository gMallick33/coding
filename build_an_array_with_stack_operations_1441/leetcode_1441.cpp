class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> answer;
        int targetIdx = 0;
        int targetSize = target.size();
        for(int i = 1; i <= n && targetIdx < targetSize; i++){
            answer.push_back("Push");
            if(i == target[targetIdx]){
                targetIdx++;
                continue;
            }
            else{
                answer.push_back("Pop");
            }
        }
        return answer;
    }
};