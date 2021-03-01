# https://leetcode.com/problems/relative-ranks/
class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        
        def print_all(values):
            print(", ".join(map(str, values)))
            
        # print_all(score)
        
        score_index = []
        len_s = len(score)
        for i in range(len_s):
            score_index.append((i, score[i]))
        # print_all(score_index)
        
        score_index = sorted(score_index, key=lambda x: x[1], reverse=True)
        # print_all(score_index)
        
        score_str = [None] * len_s

        for i in range(len_s):
            x = score_index[i]
            
            if i == 0:
                score_str[x[0]] = "Gold Medal"
            elif i == 1:
                score_str[x[0]] = "Silver Medal"
            elif i == 2:
                score_str[x[0]] = "Bronze Medal"
            else:
                score_str[x[0]] = str(i + 1)

        return score_str
