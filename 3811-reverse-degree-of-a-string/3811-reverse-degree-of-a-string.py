class Solution(object):
    def reverseDegree(self, s):
        """
        :type s: str
        :rtype: int
        """
        rev_degree = 0
        for idx, ch in enumerate(s):
            rev_code = (ord('z') - ord(ch) + 1) * (idx + 1)
            rev_degree += rev_code
        
        return rev_degree
        