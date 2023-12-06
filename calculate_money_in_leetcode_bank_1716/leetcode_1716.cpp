class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int money = weeks * 28;
        money += 7 * ((weeks - 1) * weeks) / 2;

        if(n % 7) {
            int extraDays = n % 7;
            int addMoney = weeks + 1;
            for(int i = 0; i < extraDays; i++) {
                money += addMoney;
                addMoney++;
            }
        }
        return money;
    }
};