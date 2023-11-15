class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        int n = grid.size();
        if(n == 1 && grid[0][0] == 0)
            return 1;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, 1, -1, -1, 0, 1};
        dist[0][0] = 0;
        q.push({1, {0, 0}}); //dist, source
        while(!q.empty())
        {
                auto p = q.front();
                q.pop();
                int dis = p.first;
                int x = p.second.first;
                int y = p.second.second;

                for(int i = 0; i < 8; i++)
                {

                    int X = x + dx[i];
                    int Y = y + dy[i];

                    if(X >= 0 && Y >= 0 && X < n && Y < n && grid[X][Y] == 0 && dist[X][Y] > dis + 1)
                    {
                        dist[X][Y] = dis + 1;
                        if(X == n - 1 && Y == n - 1)
                            return dis + 1;
                        q.push({dis + 1, {X, Y}});
                        grid[X][Y] = 1;
                    }
                    
                }
        }
        return -1;
    }
};