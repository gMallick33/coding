class Solution {
public:
    
    // void func(int idx, vector<int> &answer_partial, vector<vector<int>> &answer, vector<int> &candidates, int target){
    //     if(target == 0){
    //         answer.push_back(answer_partial);
    //         return;
    //     }
    //     for(int i = idx; i < candidates.size(); i++){
    //         if(i != idx && candidates[i] == candidates[i - 1]) continue;
    //         if(candidates[i] <= target){
    //             answer_partial.push_back(candidates[i]);
    //             func(i + 1, answer_partial, answer, candidates, target - candidates[i]);
    //             answer_partial.pop_back();
    //         }
    //     }
    // }
    
    void func(int idx, vector<int> &answer_partial, vector<vector<int>> &answer, vector<int> &candidates, int target){
        if(target == 0){
            answer.push_back(answer_partial);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(i != idx && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] <= target){
                answer_partial.push_back(candidates[i]);
                func(i + 1, answer_partial, answer, candidates, target - candidates[i]);
                answer_partial.pop_back();
            }
            else break;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> answer_partial;
        func(0, answer_partial, answer, candidates, target);
        return answer;
    }
};