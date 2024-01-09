class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int start = arr[0][0], end = arr[0][1];
        int i = 1;
        while(i < n)
        {
            if(arr[i][0] <= end)
            {
                if(arr[i][1] > end)
                    end = arr[i][1];
                i++;
            }
            else
            {
                ans.push_back({start, end});
                // i++;
                start = arr[i][0];
                end = arr[i][1];
            }
        }
        ans.push_back({start, end});

        return ans;
    }
};