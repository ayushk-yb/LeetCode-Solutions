class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = set('aeiouAEIOU')

        charVowels = [ch for ch in s if ch in vowels]
        charVowels.sort()

        result = []
        vowelIndex = 0

        for ch in s:
            if ch in vowels:
                result.append(charVowels[vowelIndex])
                vowelIndex += 1
            else:
                result.append(ch)
        
        return ''.join(result)
