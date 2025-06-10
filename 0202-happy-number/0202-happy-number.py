class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        seenSet = set()

        def happySum(num):
            curr_sum = 0
            while num:
                rem = num % 10
                num = num // 10

                curr_sum += rem * rem
            
            return curr_sum
        
        if n == 1:
            return True
        
        while n != 1 and n not in seenSet:
            seenSet.add(n)
            n = happySum(n)
        
        return True if n == 1 else False

