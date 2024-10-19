class Solution(object):
    def productExceptSelf(self, nums):
        n = len(nums)
        left = [1] * n
        right = [1] * n
        
        prev = 1
        for i in range(0, n - 1):
            left[i + 1] = prev * nums[i]
            prev = left[i + 1]
        
        prev = 1
        for i in range(n - 2, -1, -1):
            right[i] = prev * nums[i + 1]
            prev = right[i]
        
        ans = []
        for i in range(n):
            ans.append(left[i] * right[i])
        
        return ans