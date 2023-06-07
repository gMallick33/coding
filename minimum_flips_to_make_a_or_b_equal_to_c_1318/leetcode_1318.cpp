class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;

        for(int i = 31; i >= 0; i--){
            int aBit = (a >> i) & 1;
            int bBit = (b >> i) & 1;
            int cBit = (c >> i) & 1;
            
            if(cBit == 1){
                if(aBit == 1 || bBit == 1) continue;
                else count++;
            }
            else{
                if(aBit == 0 && bBit == 0) continue;
                else{
                    if(aBit == 1) count++;
                    if(bBit == 1) count++;
                }
            }
        }
        return count;
    }
};