# https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.letter_trie = {}
        self.is_word = False

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if not word:
            return
        len_w = len(word)
        if len_w == 0:
            return
        trie = self.letter_trie.get(word[0], Trie())
        if len_w == 1:
            trie.is_word = True
        else:
            trie.insert(word[1:])
        self.letter_trie[word[0]] = trie

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        if not word:
            return False
        len_w = len(word)
        if len_w == 0:
            return True
        trie = self.letter_trie.get(word[0])
        if not trie:
            return False
        if len_w == 1:
            return trie.is_word
        else:
            return trie.search(word[1:])

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        if not prefix:
            return False
        len_w = len(prefix)
        if len_w == 0:
            return True
        trie = self.letter_trie.get(prefix[0])
        if not trie:
            return False
        if len_w == 1:
            return True
        else:
            return trie.startsWith(prefix[1:])


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
