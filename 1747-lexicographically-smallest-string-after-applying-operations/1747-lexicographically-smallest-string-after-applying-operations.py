class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        seen = set()
        q = deque([s])
        smallest = s
        n = len(s)

        while q:
            curr = q.popleft()
            if curr in seen:
                continue
            seen.add(curr)
            smallest = min(smallest, curr)

            arr = list(curr)
            for i in range(1, n, 2):
                arr[i] = str((int(arr[i]) + a) % 10)
            
            added = "".join(arr)

            rotated = curr[-b:] + curr[:-b]

            if added not in seen:
                q.append(added)
            if rotated not in seen:
                q.append(rotated)
        
        return smallest
        