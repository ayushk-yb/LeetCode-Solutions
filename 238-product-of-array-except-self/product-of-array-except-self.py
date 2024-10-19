class Solution(object):
    def productExceptSelf(self, nums):
        n = len(nums)
        ans = [1] * n
        
        prev = 1
        for i in range(0, n):
            ans[i] = prev
            prev = prev * nums[i]
        
        prev = 1
        for i in range(n - 1, -1, -1):
            ans[i] *= prev
            prev = prev * nums[i]
        
        return ans