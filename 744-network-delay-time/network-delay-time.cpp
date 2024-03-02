class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
        }
        
        vector<int> minTime(n + 1, INT_MAX);
        minTime[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int u = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            if (time > minTime[u]) continue;

            for (auto neighbor : graph[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                if (minTime[u] + w < minTime[v]) {
                    minTime[v] = minTime[u] + w;
                    pq.push({minTime[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, minTime[i]);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};