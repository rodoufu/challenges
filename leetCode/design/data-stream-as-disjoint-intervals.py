# https://leetcode.com/problems/data-stream-as-disjoint-intervals/
class SummaryRanges:
    def __init__(self):
        self.numbers = [False] * 10001
        self.intervals = None
        self.max_so_far = 0

    def addNum(self, value: int) -> None:
        self.numbers[value] = True
        self.intervals = None
        self.max_so_far = max(self.max_so_far, value)

    def getIntervals(self) -> List[List[int]]:
        if self.intervals:
            return self.intervals
        
        self.intervals = [[]]

        last_value = 0
        for i in range(self.max_so_far + 1):
            num = self.numbers[i]

            if not num:
                continue
            
            # print(f"i: {i}, last_intervals: {self.intervals[-1]}")
            match len(self.intervals[-1]):
                case 0:
                    self.intervals[-1].append(i)
                case 1:
                    if i != last_value + 1:
                        self.intervals[-1].append(last_value)
                        self.intervals.append([i])
                case 2:
                    self.intervals.append([i])

            last_value = i
        
        if len(self.intervals[-1]) == 1:
            self.intervals[-1].append(last_value)
        
        if len(self.intervals) == 1 and len(self.intervals[0]) == 0:
            self.intervals = []

        return self.intervals
        


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()
