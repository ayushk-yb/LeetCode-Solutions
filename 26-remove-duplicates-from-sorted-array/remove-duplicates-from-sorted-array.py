class Solution(object):
    def removeDuplicates(self, nums):
        lastVal = nums[0]
        n = len(nums)
        k = 1
        for i in range(n):
            if i == 0:
                continue
            if nums[i] != lastVal:
                nums[k] = nums[i]
                lastVal = nums[k]
                k += 1
        
        return k
        