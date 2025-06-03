class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        curr_min = curr_max = result = nums[0]
        i = 1
        while i < n:
            num = nums[i]
            if num < 0:
                curr_min, curr_max = curr_max, curr_min
            
            curr_min = min(num, num * curr_min)
            curr_max = max(num, num * curr_max)

            result = max(result, curr_max)
            i += 1
        
        return result