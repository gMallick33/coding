class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        int idx1 = 0;
        int idx2 = 0;
        vector<vector<int>> answer;
        map<pair<int, int>, int> indexMap;
        indexMap[{0, 0}]++;
        minHeap.push({nums1[idx1] + nums2[idx2], {idx1, idx2}});
        while(k-- && !minHeap.empty()){
            auto front = minHeap.top();
            idx1 = front.second.first;
            idx2 = front.second.second;
            minHeap.pop();
            answer.push_back({nums1[idx1], nums2[idx2]});
            cout << k << endl;
            if(idx1 < n1 -1 ){
                if(indexMap.find({idx1 + 1, idx2}) == indexMap.end()){
                    indexMap[{idx1 + 1, idx2}]++;
                    minHeap.push({nums1[idx1 + 1] + nums2[idx2], {idx1 + 1, idx2}});
                }
            }
            if(idx2 < n2 - 1){
                if(indexMap.find({idx1, idx2 + 1}) == indexMap.end()){
                    indexMap[{idx1, idx2 + 1}]++;
                    minHeap.push({nums1[idx1] + nums2[idx2 + 1], {idx1, idx2 + 1}});
                }
            }
        }
        return answer;
    }
};