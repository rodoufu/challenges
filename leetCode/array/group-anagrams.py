# https://leetcode.com/problems/group-anagrams
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_words = {}

        for word in strs:
            word_a = "".join(sorted(word)) 
            word_a_l = anagram_words.get(word_a, [])
            word_a_l.append(word)
            anagram_words[word_a] = word_a_l
        
        return [x for x in anagram_words.values()]
        
