class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long long> f(31);
        f[0] = 1;
        for(int i = 1; i < 31; i++) f[i] = 2 * f[i - 1] + 1;
        int plus = 1;
        int answer = 0;
        for(int i = 30; i >= 0; i--){
            bool isIthBitSet = ((1 << i) & n) != 0;
            if(!isIthBitSet) continue;
            if(plus) answer += f[i];
            else answer -= f[i];
            plus ^= 1;

        }
        return answer;
    }
};