class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count, candidate = 0, 0
        n = len(nums)
        for i in range(n):
            if count == 0:
                candidate = nums[i]
                count += 1
            elif nums[i] == candidate:
                count += 1
            else:
                count -= 1
        
        return candidate
