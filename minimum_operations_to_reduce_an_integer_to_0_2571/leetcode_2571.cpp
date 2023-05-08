class Solution {
public:
    int minOperations(int n) {
        int dummyN = n;
        int ops = 0;
        while(dummyN > 0){
            if(dummyN & 1){
                ops++;
                dummyN >>= 1;
                if(!(dummyN & 1)) continue;
                while(dummyN & 1) dummyN >>= 1;
                dummyN |= 1;
            }
            else{
                dummyN >>= 1;
            }
        }
        return ops;
    }
};