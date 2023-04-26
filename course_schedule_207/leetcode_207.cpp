class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjMatrix(numCourses);
        vector<int> inDegrees(numCourses, 0);
        int n = prerequisites.size();
        for(int i = 0; i < n; i++){
            adjMatrix[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inDegrees[prerequisites[i][1]]++;
        }
        queue<int> myQueue;
        for(int i = 0; i < numCourses; i++){
            if(inDegrees[i] == 0) myQueue.push(i);
        }
        int count = 0;
        while(!myQueue.empty()){
            int front = myQueue.front();
            myQueue.pop();
            count++;
            for(auto neigh: adjMatrix[front]){
                inDegrees[neigh]--;
                if(inDegrees[neigh] == 0) myQueue.push(neigh);
            }
        }
        if(count == numCourses) return true;
        else return false;
    }
};