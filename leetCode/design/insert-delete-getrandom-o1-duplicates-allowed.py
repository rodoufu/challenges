# https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
import random

class RandomizedCollection:

    def __init__(self):
        self.number_indexes = {}
        self.numbers = []

    def insert(self, val: int) -> bool:
        # print(f"insert - val: {val}, numbers: {self.numbers}, num_idx: {self.number_indexes}")
        resp = True 
        if val in self.number_indexes:
            resp = False
        self.number_indexes[val] = self.number_indexes.get(val, set()) 
        self.number_indexes[val].add(len(self.numbers)) 
        self.numbers.append(val)

        # print(f"insert - val: {val}, numbers: {self.numbers}, num_idx: {self.number_indexes} end")
        return resp 

    def remove(self, val: int) -> bool:
        # print(f"remove - val: {val}, numbers: {self.numbers}, num_idx: {self.number_indexes}")
        if val not in self.number_indexes:
            # print(f"remove - val: {val}, numbers: {self.numbers}, num_idx: {self.number_indexes} end1")
            return False
        val_index = max(self.number_indexes.get(val))
        self.number_indexes.get(val).remove(val_index)
        if len(self.number_indexes.get(val)) == 0:
            del self.number_indexes[val]
            
        to_fix = self.numbers.pop()
        if to_fix == val:
            # print(f"remove - val: {val}, numbers: {self.numbers}, num_idx: {self.number_indexes} end2")
            return True
        
        self.numbers[val_index] = to_fix
        to_fix_index = max(self.number_indexes[to_fix])
        self.number_indexes[to_fix].remove(to_fix_index)
        self.number_indexes[to_fix].add(val_index)

        # print(f"remove - val: {val}, numbers: {self.numbers}, num_idx: {self.number_indexes} end3")
        return True

    def getRandom(self) -> int:
        index = random.randint(0, len(self.numbers) - 1)
        # print(f"index: {index}, numbers: {self.numbers}, num_idx: {self.number_indexes}")
        return self.numbers[index]


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
