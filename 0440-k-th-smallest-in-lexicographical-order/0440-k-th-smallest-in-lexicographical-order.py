class Solution(object):
    def findKthNumber(self, n, k):
        def count_prefix_steps(prefix):
            steps = 0
            first, last = prefix, prefix

            while first <= n:
                steps += (min(n, last) - first + 1)

                first *= 10
                last = last * 10 + 9
            
            return steps
        
        curr = 1
        k -= 1

        while k > 0:
            steps = count_prefix_steps(curr)

            if steps <= k:
                curr += 1
                k -= steps
            else:
                curr *= 10
                k -= 1
        
        return curr

