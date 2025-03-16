class Solution(object):
    def numCarsForTime(self, time, rank):
        return math.floor(math.sqrt(time / rank))

    def repairCars(self, ranks, cars):
        """
        :type ranks: List[int]
        :type cars: int
        :rtype: int
        """
        max_time = min(ranks) * cars * cars
        min_time = 1
        ans = 0
        while min_time < max_time:
            mid_time = (min_time + max_time) // 2
            total_cars = 0
            for rank in ranks:
                total_cars += self.numCarsForTime(mid_time, rank)
            
            if total_cars >= cars:
                max_time = mid_time  
            else:
                min_time = mid_time + 1

        return min_time
