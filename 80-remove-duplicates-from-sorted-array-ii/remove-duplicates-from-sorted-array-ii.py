class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = 0
        i = 0
        n = len(nums)
        while i < n:
            count = 1
            while i < n - 1 and nums[i] == nums[i + 1]:
                i += 1
                count += 1
            
            for k in range(min(2, count)):
                nums[l] = nums[i]
                l += 1
            i += 1
        
        return l