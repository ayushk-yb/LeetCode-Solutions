class Solution {
public:
    void solve(int i, int j, vector<vector<int>> &mat, vector<vector<bool>> &vis)
    {
        int n = mat.size();
        int m = mat[0].size();
        vis[i][j] = true;
        for(int x = 0; x < n; x++)
        {
            if(mat[x][j] != 0)
            {
                mat[x][j] = 0;
                vis[x][j] = true;
            }

        }
        for(int x = 0; x < m; x++)
        {
            if(mat[i][x] != 0)
            {
                mat[i][x] = 0;
                vis[i][x] = true;
            }

        }
        
    }
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0 && !vis[i][j])
                    solve(i, j, mat, vis);
            }
        }        
    }
};