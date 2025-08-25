class Solution:
    def isNumber(self, s: str) -> bool:
        seen_decimal = False
        seen_exponent = False
        seen_digit = False
        for i, ch in enumerate(s):
            if ch.isdigit():
                seen_digit = True

            elif ch == '.':
                if seen_decimal or seen_exponent:
                    return False
                
                seen_decimal = True

            elif ch == '-' or ch == '+':
                if i != 0 and s[i - 1] != 'e' and s[i - 1] != 'E':
                    return False

            elif ch == 'e' or ch == 'E':
                if not seen_digit or seen_exponent:
                    return False
                
                seen_digit = False
                seen_exponent = True
            
            else:
                return False
        
        if not seen_digit:
            return False
                
        return True 