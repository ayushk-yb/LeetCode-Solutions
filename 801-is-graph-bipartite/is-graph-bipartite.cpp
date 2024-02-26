class Solution {
public:
    bool bfs(int i, vector<vector<int>> &graph, vector<int> &vis)
    {
        queue<int> q;
        vis[i] = 0;
        q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int neighbor : graph[node])
            {
                if(vis[neighbor] == -1)
                {
                    q.push(neighbor);
                    vis[neighbor] = !vis[node];
                }
                else
                {
                    if(vis[neighbor] == vis[node])
                        return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i = 0; i < n; i++)
        {
            if(vis[i] == -1)
            {
                if(bfs(i, graph, vis) == false)
                    return false;
            }
        }

        return true;
    }
};