class Solution {
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }

        return true;
    }
    void solve(int idx, int n, string &s, vector<string> &temp, vector<vector<string>> &res)
    {
        if(idx == n)
        {
            res.push_back(temp);
            return;
        }

        for(int i = idx; i < n; i++)
        {
            if(isPalindrome(idx, i, s))
            {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, n, s, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> temp;
        solve(0, n, s, temp, res);

        return res;
    }
};