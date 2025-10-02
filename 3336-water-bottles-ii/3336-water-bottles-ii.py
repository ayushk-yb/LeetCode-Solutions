class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        drunk = numBottles
        empty = numBottles
        
        while empty >= numExchange:
            # new_full = empty // numExchange
            drunk += 1
            # empty = (empty % numExchange) + new_full
            empty = empty - numExchange
            numExchange += 1
            empty += 1
        
        return drunk
        
        return drunk           