class Solution {
public:
    // bool isAnagram(string &s, string &t)
    // {
    //     if(s.length() != t.length())
    //         return false;
            
    //     vector<int> freq(26, 0);
    //     int n = s.length();

    //     for(int i = 0; i < n; i++)
    //     {
    //         freq[s[i] - 'a']++;
    //     }

    //     for(int i = 0; i < n; i++)
    //     {
    //         freq[t[i] - 'a']--;
    //     }

    //     for(int i = 0; i < 26; i++)
    //     {
    //         if(freq[i] != 0)
    //             return false;
    //     }

    //     return true;
    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anaMap;
       for(auto str : strs)
       {
            string sortString = str;
            sort(sortString.begin(), sortString.end());
            anaMap[sortString].push_back(str);
       }

       for(auto it : anaMap)
       {
            vector<string> temp;
            for(auto str : it.second)
            {
                temp.push_back(str);
            }
            result.push_back(temp);
       }

        return result;
    }
};