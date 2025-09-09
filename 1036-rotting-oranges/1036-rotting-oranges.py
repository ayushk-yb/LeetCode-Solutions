class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        queue = deque()
        n, m = len(grid), len(grid[0])
        time = 0
        
        def bfs():
            for i in range(n):
                for j in range(m):
                    if grid[i][j] == 2:
                        queue.append([i, j])
            
            while queue:
                size = len(queue)
                while size > 0:
                    size -= 1
                    curr = queue.popleft()
                    x, y = curr[0], curr[1]

                    for i, j in dirs:
                        X = x + i
                        Y = y + j

                        if X >= 0 and X < n and Y >= 0 and Y < m and grid[X][Y] == 1:
                            grid[X][Y] = 2
                            queue.append([X, Y])
                
                if queue:
                    nonlocal time
                    time += 1
            
        bfs()

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    return -1
        
        return time
                
