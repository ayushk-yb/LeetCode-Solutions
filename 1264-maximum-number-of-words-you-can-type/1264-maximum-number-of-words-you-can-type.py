class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        brokenSet = set(brokenLetters)
        typableWords = 0
        isBroken = False

        for ch in text:
            if ch == " ":
                if not isBroken:
                    typableWords += 1
                isBroken = False
            else:
                if ch in brokenSet:
                    isBroken = True
        if not isBroken:
            typableWords += 1

        return typableWords
