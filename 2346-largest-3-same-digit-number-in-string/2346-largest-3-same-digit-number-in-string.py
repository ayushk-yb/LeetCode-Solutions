class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n = len(num)
        max_good = -1

        # for i in range(n - 2):
        #     sub_str = num[i:i+3]

        #     if sub_str[0] == sub_str[1] == sub_str[2]:
        #         if sub_str > max_good:
        #             max_good = sub_str
        
        # return max_good

        for i in range(n - 2):
            if num[i] == num[i + 1] == num[i + 2]:
                if int(num[i]) > max_good:
                    max_good = int(num[i])
        
        return "" if max_good == -1 else str(max_good) * 3
        

