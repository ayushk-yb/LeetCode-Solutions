class Solution(object):
    def sortedSquares(self, nums):
        n = len(nums)
        res = [0] * n
        i = 0 
        j = n - 1
        s = n - 1
        while s >= 0:
            if abs(nums[i]) < abs(nums[j]):
                res[s] = nums[j] * nums[j]
                j -= 1
                s -= 1
            else:
                res[s] = nums[i] * nums[i]
                i += 1
                s -= 1
        
        return res
        