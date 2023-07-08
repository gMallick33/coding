class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long> sumAdjacent;
        for(int i = 0; i < n - 1; i++){
            sumAdjacent.push_back((long long)weights[i] + weights[i + 1]);
        }
        sort(sumAdjacent.begin(), sumAdjacent.end());
        long long maxSum = 0, minSum = 0;
        for(int i = 0; i < k - 1; i++){
            minSum += sumAdjacent[i];
            maxSum += sumAdjacent[n - 2 - i];
        }
        return maxSum - minSum;
    }
};