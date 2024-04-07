class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int low = 0, high = 0; // Range of possible open parentheses
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                low++;
                high++;
            } else if (s[i] == ')') {
                if (low > 0) low--;
                high--;
            } else { // '*'
                if (low > 0) low--; // Treat '*' as '('
                high++; // Treat '*' as ')'
            }
            if (high < 0) return false; // More ')' than '('
        }
        return low == 0; // All '(' are matched
    }
};
