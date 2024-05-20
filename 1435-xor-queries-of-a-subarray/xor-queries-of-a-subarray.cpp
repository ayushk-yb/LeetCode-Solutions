class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int size = queries.size();
        unordered_map<int, int> xorMap;
        xorMap[0] = arr[0];
        for(int i = 1; i < n; i++){
            xorMap[i] = xorMap[i - 1] ^ arr[i];
        }

        vector<int> ans;
        for(int i = 0; i < size; i++){
            int left = queries[i][0], right = queries[i][1];
            if(left > 0){
                ans.push_back(xorMap[right] ^ xorMap[left - 1]);
            }
            else{
                ans.push_back(xorMap[right]);
            }
        }

        return ans;
    }
};