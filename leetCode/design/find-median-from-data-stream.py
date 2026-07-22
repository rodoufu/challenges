# https://leetcode.com/problems/find-median-from-data-stream/
import heapq

class MedianFinder:
    def __init__(self):
        self.mx = []
        self.mn = []

    def addNum(self, num: int) -> None:
        if len(self.mx) == 0:
            self.mx.append(num)
            return

        if num < self.mx[0]:
            heapq.heappush_max(self.mx, num)
        else:
            heapq.heappush(self.mn, num)
        
        if len(self.mn) > len(self.mx):
            value = heapq.heappop(self.mn)
            heapq.heappush_max(self.mx, value)
        elif len(self.mn) + 2 == len(self.mx):
            value = heapq.heappop_max(self.mx)
            heapq.heappush(self.mn, value)

    def findMedian(self) -> float:
        if len(self.mx) == 0:
            return 0
        if (len(self.mx) + len(self.mn)) % 2 == 1:
            return self.mx[0]
        return (self.mx[0] + self.mn[0]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
