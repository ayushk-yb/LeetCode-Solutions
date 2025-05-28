class Solution(object):
    def jump(self, nums):
        l, r = 0, 0
        minJumps = 0

        while r < len(nums) - 1:
            farthestJump = 0

            for i in range(l, r + 1):
                farthestJump = max(farthestJump, i + nums[i])
            
            l = r + 1
            r = farthestJump
            minJumps += 1
        
        return minJumps
        