class DisjointSet {

    public:
        vector<int> parent, rank, size;
        DisjointSet(int n){
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1);
            for(int i = 0; i <= n; i++)
            {
                parent[i] = i;
            }
        }

        int findUPar(int node)
        {
            if(node == parent[node])
                return node;
            
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v)
        {
            int ulPar_u = findUPar(u);
            int ulPar_v = findUPar(v);

            if(ulPar_u == ulPar_v)
                return;
            if(rank[ulPar_u] < rank[ulPar_v])
            {
                parent[ulPar_u] = ulPar_v;
            }
            else if(rank[ulPar_v] < rank[ulPar_u])
            {
                parent[ulPar_v] = ulPar_u;
            }
            else
            {
                parent[ulPar_v] = ulPar_u;
                rank[ulPar_u]++;
            }
        }

        void unionBySize(int u, int v)
        {
            int ulPar_u = findUPar(u);
            int ulPar_v = findUPar(v);

            if(ulPar_u == ulPar_v)
                return;
            if(size[ulPar_u] < size[ulPar_v])
            {
                parent[ulPar_u] = ulPar_v;
                size[ulPar_v] += size[ulPar_u];
            }
            else
            {
                parent[ulPar_v] = ulPar_u;
                size[ulPar_u] += size[ulPar_v];
            }
        }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for(int i = 0; i < 4; i++)
                {
                    if(grid[row][col] == 0)
                        continue;
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1)
                    {
                        ds.unionBySize(row * n + col, nr * n + nc);
                    }
                }
            }
        }
        unordered_set<int> s;
        int ans = -1;
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(grid[row][col] == 0)
                {
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    int temp = 1;
                    for(int i = 0; i < 4; i++)
                    {
                        int nr = row + dr[i];
                        int nc = col + dc[i];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1)
                        {
                            int par = ds.findUPar(nr * n + nc);
                            if(s.find(par) == s.end())
                            {
                                temp += ds.size[par];
                                s.insert(par);
                            }
                        }
                    }
                    ans = max(ans, temp);
                    s.clear();
                }
            }
        }
        for(int cell = 0; cell < n * n; cell++)
        {
            ans = max(ans, ds.size[ds.findUPar(cell)]);
        }
        return ans;
    }
};