class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.heap = []
        self.taskMap = {}
        for userId, taskId, priority in tasks:
            self.add(userId, taskId, priority)
        

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.taskMap[taskId] = (priority, userId)
        heapq.heappush(self.heap, (-priority, -taskId, userId))
        

    def edit(self, taskId: int, newPriority: int) -> None:
        if taskId in self.taskMap:
            userId = self.taskMap[taskId][1]
            self.taskMap[taskId] = (newPriority, userId)
            heapq.heappush(self.heap, (-newPriority, -taskId, userId))
        

    def rmv(self, taskId: int) -> None:
        if taskId in self.taskMap:
            del self.taskMap[taskId]
        

    def execTop(self) -> int:
        while self.heap:
            priority, negTaskId, userId = heapq.heappop(self.heap)
            taskId = -negTaskId
            if taskId in self.taskMap:
                storedPriority, storedUser = self.taskMap[taskId]
                if storedPriority == -priority and storedUser == userId:
                    del self.taskMap[taskId]
                    return userId
    
        return -1
        


# Your TaskManager object will be instantiated and called as such:
# obj = TaskManager(tasks)
# obj.add(userId,taskId,priority)
# obj.edit(taskId,newPriority)
# obj.rmv(taskId)
# param_4 = obj.execTop()