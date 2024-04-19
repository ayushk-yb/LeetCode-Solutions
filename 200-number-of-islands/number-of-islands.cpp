class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';

        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1); 
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int n = grid.size();
        int m = grid[0].size();

        int num = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    num++;
                    dfs(grid, i, j);
                }
            }
        }
        return num++;
    }
};