MOD = 10**9 + 7
from functools import lru_cache
class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        # m, n = len(grid), len(grid[0])

        # @lru_cache(None)
        # def dfs(i, j, r):
        #     val = grid[i][j]

        #     prev_r = (r - val + k) % k

        #     if i == 0 and j == 0:
        #         return 1 if prev_r == 0 else 0
            
        #     ways = 0
        #     if i > 0:
        #         ways += dfs(i - 1, j, prev_r)
        #     if j > 0:
        #         ways += dfs(i, j - 1, prev_r)
            
        #     return ways % MOD
        
        # return dfs(m - 1, n - 1, 0)
        m, n = len(grid), len(grid[0])
        dp = [[0]*k for _ in range(n)]

        dp[0][grid[0][0] % k] = 1

        for i in range(m):
            new_dp = [[0]*k for _ in range(n)]
            for j in range(n):
                val = grid[i][j] % k
                if i == 0 and j == 0:
                    new_dp[0][val] = 1
                    continue

                for r in range(k):
                    nr = (r + val) % k
                    if i > 0:
                        new_dp[j][nr] = (new_dp[j][nr] + dp[j][r]) % MOD
                    if j > 0:
                        new_dp[j][nr] = (new_dp[j][nr] + new_dp[j-1][r]) % MOD

            dp = new_dp

        return dp[-1][0]
        