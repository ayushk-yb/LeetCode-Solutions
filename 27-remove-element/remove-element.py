class Solution(object):
    def removeElement(self, nums, val):
        n = len(nums)
        k = 0
        for i in range(n):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        
        return k

        