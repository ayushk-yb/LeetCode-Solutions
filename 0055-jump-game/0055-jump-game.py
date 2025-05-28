class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        farthestJump = 0
        for capacity in nums:
            if farthestJump < 0:
                return False
            
            if capacity > farthestJump:
                farthestJump = capacity
            
            farthestJump -= 1
        
        return True
        