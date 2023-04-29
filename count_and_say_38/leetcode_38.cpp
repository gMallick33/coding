class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        else{
            string prevAnswer = countAndSay(n - 1);
            string answer = "";
            int len = prevAnswer.length();
            
            for(int i = 0; i < len; i++){
                char ch = prevAnswer[i];
                int count = 0;
                while(i < len && prevAnswer[i] == ch){
                    i++;
                    count++;
                }
                i--;
                answer += to_string(count) + ch; 
            }
            return answer;
        }
    }
};