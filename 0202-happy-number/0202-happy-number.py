class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """

        def happySum(num):
            curr_sum = 0
            while num:
                rem = num % 10
                num = num // 10

                curr_sum += rem * rem
            
            return curr_sum
        
        if n == 1:
            return True
        
        slow = happySum(n)
        fast = happySum(happySum(n))

        while slow != fast:
            if fast == 1:
                return True
            
            slow = happySum(slow)
            fast = happySum(happySum(fast))
        
        return slow == 1

