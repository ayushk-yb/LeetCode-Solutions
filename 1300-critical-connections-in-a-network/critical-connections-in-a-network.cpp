class Solution
{
    public:
        vector<vector < int>> criticalConnections(int n, vector<vector < int>> &connections)
        {
            unordered_map<int, vector < int>> graph;
            for (const auto &connection: connections)
            {
                graph[connection[0]].push_back(connection[1]);
                graph[connection[1]].push_back(connection[0]);
            }

            vector<vector < int>> result;
            vector<int> disc(n, -1);
            vector<int> low(n, -1);
            unordered_set<int> visited;
            dfs(0, -1, 0, disc, low, visited, graph, result);

            return result;
        }
    private:
        void dfs(int node, int parent, int time, vector<int> &disc, vector<int> &low,
            unordered_set<int> &visited, const unordered_map<int, vector < int>> &graph,
                vector<vector < int>> &result)
        {

            disc[node] = low[node] = time + 1;
            visited.insert(node);

            for (const int neighbor: graph.at(node))
            {
                if (neighbor == parent) continue;

                if (visited.find(neighbor) == visited.end())
                {
                    dfs(neighbor, node, time + 1, disc, low, visited, graph, result);
                    low[node] = min(low[node], low[neighbor]);
                    if (low[neighbor] > disc[node])
                    {
                        result.push_back({ node,
                            neighbor });
                    }
                }
                else
                {
                    low[node] = min(low[node], disc[neighbor]);
                }
            }
        }
};