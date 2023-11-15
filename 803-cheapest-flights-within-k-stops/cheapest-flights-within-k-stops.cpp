class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, pair<int, int>>> q;
        vector<pair<int, int>> adj[n];
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});

        while(!q.empty())
        {
            int stops = q.front().first;
            int start = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops > k)
                continue;
            
            for(auto it : adj[start])
            {
                int node = it.first;
                int edW = it.second;

                if(cost + edW < dist[node] && stops <= k)
                {
                    dist[node] = cost + edW;
                    q.push({stops + 1, {node, dist[node]}});
                }
            }
        }

        if(dist[dst] == 1e9)
            return -1;
        
        return dist[dst];
    }
};