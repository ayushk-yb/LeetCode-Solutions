class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 1:
            return nums[0]


        def solve(nums, start, end):
            # n = len(nums)
            dp = {i : 0 for i in range(end + 1)}

            dp[end - 1] = nums[end - 1]

            for i in range(end - 2, start - 1, -1):
                dp[i] = max(dp[i + 1], nums[i] + dp[i + 2])

            return dp[start]

        return max(solve(nums, 0, n - 1), solve(nums, 1, n))