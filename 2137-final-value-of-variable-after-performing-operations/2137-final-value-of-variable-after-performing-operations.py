class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        countPlus, countMinus = 0, 0

        for op in operations:
            if op == "X++" or op == "++X":
                countPlus += 1
            else:
                countMinus += 1
        
        return countPlus - countMinus
        