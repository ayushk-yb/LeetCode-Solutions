class Solution:
    def maxDifference(self, s, k):
        n = len(s)
        ans = float('-inf')

        # Try all pairs (a, b) with a != b
        for a in range(5):
            for b in range(5):
                if a == b:
                    continue

                # Prefix sums for counts of a and b
                s1 = [0] * (n + 1)
                s2 = [0] * (n + 1)
                for i in range(1, n + 1):
                    s1[i] = s1[i - 1] + (int(s[i - 1]) == a)
                    s2[i] = s2[i - 1] + (int(s[i - 1]) == b)

                # g[pa][pb] = best s2[j] - s1[j] seen so far for that parity
                g = [[float('-inf')] * 2 for _ in range(2)]
                j = 0

                # Traverse the string with end pointer i
                for i in range(k, n + 1):
                    # Move start pointer j to ensure window is valid and improves s1/s2
                    while i - j >= k and s1[i] > s1[j] and s2[i] > s2[j]:
                        pa = s1[j] % 2  # parity of freq[a] in s[0:j]
                        pb = s2[j] % 2  # parity of freq[b] in s[0:j]
                        g[pa][pb] = max(g[pa][pb], s2[j] - s1[j])
                        j += 1

                    # For current i, check if there's a previous j such that:
                    # - freq[a] is odd in substring => pa = 1
                    # - freq[b] is even in substring => pb = 0
                    pa = s1[i] % 2
                    pb = s2[i] % 2
                    best = g[1 - pa][pb]
                    if best != float('-inf'):
                        candidate = (s1[i] - s2[i]) + best
                        ans = max(ans, candidate)

        return -1 if ans == float('-inf') else ans
