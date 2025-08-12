class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        dp = [0] * (n + 1)
        mod = 10**9 + 7

        # def solve(base, remaining):
        #     key = (base, remaining)

        #     if key in dp:
        #         return dp[key]
            
        #     curr_num = base ** x
            
        #     if curr_num > remaining:
        #         return 0
            
        #     if curr_num == remaining:
        #         return 1
            
        #     take = solve(base + 1, remaining - curr_num)
        #     skip = solve(base + 1, remaining)

        #     dp[key] = (take + skip) % mod

        #     return dp[key]
        
        base = 1
        powers = []

        while base ** x <= n:
            powers.append(base ** x)
            base += 1
        
        dp[0] = 1

        for p in powers:
            for target in range(n, p - 1, -1):
                dp[target] = (dp[target] + dp[target - p]) % mod
        
        return dp[n]
