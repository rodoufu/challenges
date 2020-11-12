# https://leetcode.com/problems/rearrange-spaces-between-words/
class Solution:
    def reorderSpaces(self, text: str) -> str:
        text_splited = text.split(' ')
        words_size = map(lambda x: len(x), text_splited)
        words_count = sum(map(lambda x: 1 if x > 0 else 0, words_size))
        words_size = map(lambda x: len(x), text_splited)
        
        letters = sum(words_size)
        len_t = len(text)
        spaces = len_t - letters
        
        spaces_between = (spaces // (words_count - 1)) if words_count > 1 else 0
        spaces_rem = spaces - spaces_between * (words_count - 1)
        
        spaces_sep = ''.join([" "] * spaces_between)
        
        return spaces_sep.join(filter(lambda x: len(x), text_splited)) + ''.join([" "] * spaces_rem)
        # return ""
