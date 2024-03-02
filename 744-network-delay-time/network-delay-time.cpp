class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> minTime(n, 1e8);
        minTime[k - 1] = 0;
        for(int i = 0; i < n; i++)
        {
            for(auto it : times)
            {
                int src = it[0] - 1;
                int target = it[1] - 1;
                int time = it[2];

                if(minTime[src] != 1e8 && minTime[src] + time < minTime[target])
                {
                    minTime[target] = minTime[src] + time;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, minTime[i]);
        }

        return (ans == 1e8) ? -1 : ans;
    }
};