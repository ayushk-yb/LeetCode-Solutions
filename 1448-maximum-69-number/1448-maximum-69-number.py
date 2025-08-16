class Solution:
    def maximum69Number (self, num: int) -> int:
        list_str = list(str(num))

        for i in range(len(list_str)):
            if list_str[i] == '6':
                list_str[i] = '9'
                break

        return int("".join(list_str))
        