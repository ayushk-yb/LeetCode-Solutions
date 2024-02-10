class Solution {
public: 
    int solve(string s, int left, int right) {
        int count = 0;
        while(left >= 0 && right < s.length() && s[left--] == s[right++]) {
            count++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++) {
            int even = solve(s, i, i+1);
            int odd = solve(s, i-1, i+1);
            ans += even + odd + 1;
        }
        return ans;
    }
};