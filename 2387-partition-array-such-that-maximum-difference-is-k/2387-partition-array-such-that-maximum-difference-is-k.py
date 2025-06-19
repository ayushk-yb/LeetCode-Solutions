class Solution(object):
    def partitionArray(self, nums, k):
        nums.sort()
        n = len(nums)
        count = 0
        i = 0

        while i < n:
            start = nums[i]
            count += 1

            while i < n and nums[i] - start <= k:
                i += 1
        
        return count
        