class Solution(object):
    def differenceOfSums(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        sum_to_n = (n * (n + 1)) / 2
        diff_sum = 0
        for i in range(m, n + 1, m):
            diff_sum += i
        
        return sum_to_n - (2 * diff_sum)