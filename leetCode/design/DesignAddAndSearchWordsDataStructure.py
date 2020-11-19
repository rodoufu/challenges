# https://leetcode.com/problems/design-add-and-search-words-data-structure/
class WordDictionary:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.words: Dict[int, Set[str]] = {}

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        len_w = len(word)
        value = self.words.get(len_w, set())
        value.add(word)
        self.words[len_w] = value

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        len_w = len(word)
        to_find = self.words.get(len_w, set())
        if word in to_find:
            return True
        for it_word in to_find:
            is_equal = True
            for i in range(len_w):
                if it_word[i] != word[i] and word[i] != '.':
                    is_equal = False
                if not is_equal:
                    break
            if is_equal:
                return True
        return False


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
