class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(char ch : s)
        {
            mp[ch]++;
        }

        string ans = "";
        for(char ch : order)
        {
            if(mp.find(ch) != mp.end())
            {
                ans.append(mp[ch], ch);
                mp.erase(ch);
            }
        }

        for(char ch : s)
        {
            if(mp.find(ch) != mp.end())
            {
                mp[ch]--;
                ans += ch;
            }
        }

        return ans;
    }
};