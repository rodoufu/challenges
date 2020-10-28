# https://leetcode.com/problems/binary-watch/
class Solution:
    def __init__(self):
        self.num_count = {}
        self.on_hour = {}
        self.on_hour[0] = set(["0:00"])
        for h in range(12):
            for m in range(60):
                on_sum = self.count_on(h) + self.count_on(m)
                value = self.on_hour.get(on_sum, set())
                value.add(f"{h}:{m:02d}")
                self.on_hour[on_sum] = value
    
    def count_on(self, x):
        if x in self.num_count:
            return self.num_count[x]
        resp = 0
        val = x
        while x:
            resp += x % 2
            x //= 2
        self.num_count[val] = resp
        # print(f"count_on({val})={resp}")
        return resp

    def readBinaryWatch(self, num: int) -> List[str]:
        # for k, v in self.num_count.items():
        #     print(f"{k}:{v}")
        # for k, v in self.on_hour.items():
        #     # if k < 7:
        #     #     continue
        #     print(f"{k}:{v}")
        if num in self.on_hour:
            return list(self.on_hour[num])
        else:
            return []
