# It needs improvement, put is running in O(n)
# https://leetcode.com/problems/lru-cache/
class LRUCache:
    def __init__(self, capacity: int):
        self.items: Dict[int, int] = {}
        self.capacity = capacity
        self.size = 0
        self.tic = 0
        self.key_time = {}
        self.time_key = {}

    def get(self, key: int) -> int:
        if key in self.items:
            old_time = self.key_time[key]
            del self.time_key[old_time]
            
            self.key_time[key] = self.tic
            self.time_key[self.tic] = key
            
            self.tic += 1
            return self.items[key]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        skip = key in self.items
        
        if skip:
            old_time = self.key_time[key]
            del self.time_key[old_time]

        self.items[key] = value
        self.key_time[key] = self.tic
        self.time_key[self.tic] = key
        self.tic += 1

        if skip:
            return

        self.size += 1        
        if self.size > self.capacity:
            self.size = self.capacity
            
            # O(n)
            oldest = min(self.time_key)

            evict_key = self.time_key[oldest]
            del self.time_key[oldest]
            del self.key_time[evict_key]
            del self.items[evict_key]
            # print(f"{self.time_key}")


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
