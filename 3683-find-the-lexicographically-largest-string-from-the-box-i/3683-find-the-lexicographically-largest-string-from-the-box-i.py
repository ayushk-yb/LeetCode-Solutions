class Solution(object):
    def answerString(self, word, numFriends):
        if numFriends == 1:
            return word
        res = ""
        length_req = len(word) - numFriends + 1

        for i in range(len(word)):
            temp = word[i : i + length_req]
            if temp > res:
                res = temp
        
        return res
