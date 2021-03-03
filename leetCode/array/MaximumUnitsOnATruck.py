# https://leetcode.com/problems/maximum-units-on-a-truck/
class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        lenb = len(boxTypes)
        
        boxTypes = sorted(boxTypes, key=lambda x: x[1], reverse=True)
        
        # print(', '.join(map(str, boxTypes)))

        box_id = 0
        items = 0
        
        while truckSize > 0 and box_id < lenb:
            box = boxTypes[box_id]
            num_boxes = min(box[0], truckSize)
            # print(f"box: {box}, n: {num_boxes}, items: {items}, truckSize; {truckSize}")

            items += num_boxes * box[1]
            truckSize -= num_boxes
            box_id += 1
        
        return items
