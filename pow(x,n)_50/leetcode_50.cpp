class Solution {
public:
    double func(double x, int n){
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1 / x;
        if(n % 2 == 0){
            double ans_par = func(x, n / 2);
            return ans_par * ans_par;
        }
        else{
            double ans_par = func(x, n / 2);
            if(n < 0) return ans_par * ans_par * 1 / x;
            else return ans_par * ans_par * x;
            
        }
    }
    double myPow(double x, int n) {
        return func(x, n);
    }
};