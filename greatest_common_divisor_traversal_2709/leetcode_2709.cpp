class Solution {
public:
    vector<int> getPrimeFactors(int x){
        vector<int> primeFactors;
        for(int i = 2; i * i <= x; i++){
            if(x % i == 0){
                primeFactors.push_back(i);
                while(x % i == 0) x /= i;
            }
        }
        if(x != 1) primeFactors.push_back(x);
        return primeFactors;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        map<int, int> myMap;
        vector<vector<int>> adjList(n);
        for(int i = 0; i < n; i++){
            int elem = nums[i];
            if(elem == 1) return false;
            vector<int> primeFactors = getPrimeFactors(elem);
            for(int prime: primeFactors){
                if(myMap.find(prime) != myMap.end()){
                    adjList[i].push_back(myMap[prime]);
                    adjList[myMap[prime]].push_back(i);
                }
                else{
                    myMap[prime] = i;
                }
            }
        }
        int visitCount = 0;
        vector<int> visited(n, 0);
        queue<int> bfsQueue;
        bfsQueue.push(0);
        while(!bfsQueue.empty()){
            int front = bfsQueue.front();
            bfsQueue.pop();
            if(visited[front]) continue;
            visited[front] = 1;
            visitCount++;
            for(auto neigh: adjList[front]){
                if(!visited[neigh]) bfsQueue.push(neigh);
            }
        }
        cout << visitCount << " " << n << endl;
        if(visitCount == n) return true;
        else return false;
    }
};