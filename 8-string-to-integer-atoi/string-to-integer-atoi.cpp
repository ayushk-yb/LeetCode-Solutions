class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(s[i] == ' ')
        {
            i++;
        }
        int sign = 1;
        if(s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(s[i] == '+')
            i++;
        int num = 0;
        while(i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';
            if(num > (INT_MAX - digit) / 10)
            {
                return (sign == -1) ? INT_MIN : INT_MAX;
            }

            num = num * 10 + digit;
            i++;
        }

        return num * sign;
    }
};