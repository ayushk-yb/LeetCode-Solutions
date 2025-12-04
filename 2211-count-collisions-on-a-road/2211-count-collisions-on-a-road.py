class Solution:
    def countCollisions(self, directions: str) -> int:
        n = len(directions)
        i, j = 0, len(directions) - 1

        while i < n and directions[i] == 'L':
            i += 1
        
        while j >= 0 and directions[j] == 'R':
            j -= 1
        
        collisions = 0

        for car in range(i, j + 1):
            if directions[car] != 'S':
                collisions += 1
        
        return collisions