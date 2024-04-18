class Solution {
public:
    int travel(vector<vector<int>> &grid, int i, int j, int n, int m)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        {
            return 1;
        }

        if(grid[i][j] == -1)
        {
            return 0;
        }
        
        grid[i][j] = -1;

        return travel(grid, i + 1, j, n, m) +
            travel(grid, i - 1, j, n, m) +
            travel(grid, i, j + 1, n, m) + 
            travel(grid, i, j - 1, n, m);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                    perimeter += travel(grid, i, j, rows, cols);
            }
        }

        return perimeter;
    }
};