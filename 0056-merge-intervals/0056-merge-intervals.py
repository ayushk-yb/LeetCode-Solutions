class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        intervals.sort()
        merged = []
        start, end = intervals[0][0], intervals[0][1]
        i = 1
        while i < n:
            if end >= intervals[i][0]:
                if end < intervals[i][1]:
                    end = intervals[i][1]
                i += 1
            else:
                merged.append([start, end])
                start = intervals[i][0]
                end = intervals[i][1]
        
        merged.append([start, end])
        
        return merged
