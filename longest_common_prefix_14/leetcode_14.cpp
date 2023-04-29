class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";
        int i = 0;
        int n = strs.size();
        while(true){
            char c = strs[0][i];
            int j = 0;
            bool while_cond = true;
            for(j; j < n; j++){
                if(i >= strs[j].length()){
                    while_cond = false;
                    break;
                }
                if(strs[j][i] == c){
                    continue;
                }
                else{
                    break;
                }
            }
            if(!while_cond){
                break;
            }
            if(j == n){
                answer += c;
            }
            else{
                break;
            }
            i++;
        }
        return answer;
    }
};