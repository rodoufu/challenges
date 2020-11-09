# https://leetcode.com/problems/check-array-formation-through-concatenation/
class Solution:
    def gen_array_map(self, pieces: List[List[int]]) -> Dict[int, Dict[int, List]]:
        first_size_array = {}
        for piece in pieces:
            if not piece:
                continue
            first_size_array[piece[0]] = first_size_array.get(piece[0], {})
            len_p = len(piece)
            first_size_array[piece[0]][len_p] = first_size_array[piece[0]].get(len_p, [])
            first_size_array[piece[0]][len_p].append([piece, False])
        return first_size_array
    
    def reset_array_map(self, first_size_array: Dict[int, Dict[int, List]]):
        for len_piece in first_size_array.values():
            for pieces in len_piece.values():
                pieces = [[x[0], False] for x in pieces]
                
    def generate(self, arr: List[int], pieces: List[List[int]], first_size_array: Dict[int, Dict[int, List]], index: int) -> bool:
        len_a = len(arr)
        if index == len_a:
            return True
        
        if arr[index] not in first_size_array:
            return False
        
        for len_p, pieces_it in first_size_array[arr[index]].items():
            for pieces_used in pieces_it:
                len_p = len(pieces_used[0])
                if pieces_used[1] or len_a < index + len_p:
                    continue
                pieces = pieces_used[0]
                should_skip_to_next = False
                for i in range(len_p):
                    if arr[index + i] != pieces[i]:
                        should_skip_to_next = True
                        break
                if should_skip_to_next:
                    continue
                
                pieces_used[1] = True
                if self.generate(arr, pieces, first_size_array, index + len_p):
                    return True
                pieces_used[1] = False
                

        return False

    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        first_size_array = self.gen_array_map(pieces)
        
        return self.generate(arr, pieces, first_size_array, 0)
        
