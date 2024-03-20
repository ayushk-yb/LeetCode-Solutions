class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            freqMap[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(auto it : freqMap)
        {
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};