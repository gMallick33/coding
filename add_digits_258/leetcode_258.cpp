class Solution {
public:
    int addDigits(int num) {
        int temp = num;
        int sum = 0;
        int digit;
        while(num >= 10){
            while(temp){
                digit = temp % 10;
                temp = temp / 10;
                sum += digit;
            }
            num = sum;
            sum = 0;
            temp = num;
        }
        return num;
    }
};