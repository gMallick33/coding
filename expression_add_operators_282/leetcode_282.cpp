class Solution {
public:
    void dfs(int start, string &num, int target, long long curr, long long prev, string answerPartial, vector<string> &answer){
        if(start == num.size() && curr + prev == target){
            answer.push_back(answerPartial);
        }
        for(int i = 1; start + i <= num.size(); i++){
            string s = num.substr(start, i);
            long long sNum = stoll(s);
            if(to_string(sNum).size() != s.size()) continue;
            if(!start) dfs(i, num, target, sNum, 0, s, answer);
            else{
                dfs(start + i, num, target, sNum, curr + prev, answerPartial + '+' + s, answer);
                dfs(start + i, num, target, -sNum, curr + prev, answerPartial + '-' + s, answer);
                dfs(start + i, num, target, curr * sNum, prev, answerPartial + '*' + s, answer);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> answer;
        dfs(0, num, target, 0, 0, "", answer);
        return answer;
    }
};