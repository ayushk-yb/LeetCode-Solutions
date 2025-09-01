import heapq

class Solution(object):
    def maxAverageRatio(self, classes, extraStudents):
        def gain(passi, totali):
            return (passi + 1.0) / (totali + 1.0) - (passi * 1.0) / totali

        heap = []
        for passi, totali in classes:
            heapq.heappush(heap, (-gain(passi, totali), passi, totali))

        for _ in range(extraStudents):
            g, passi, totali = heapq.heappop(heap)
            passi, totali = passi + 1, totali + 1
            heapq.heappush(heap, (-gain(passi, totali), passi, totali))

        total_ratio = 0.0
        while heap:
            _, passi, totali = heapq.heappop(heap)
            total_ratio += passi * 1.0 / totali

        return total_ratio / len(classes)

        