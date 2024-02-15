class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> v;
        string temp = "";
        bool spaceFound = false;
        int i = 0;
        while(s[i] == ' ')
        {
            i++;
        }
        while(i < n)
        {
            char c = s[i];
            if(c != ' ')
            {
                temp += c;
            }
            else
            {
                if(i + 1 < n && s[i + 1] != ' ')
                {
                    v.push_back(temp);
                    temp = "";
                }
            }
            i++;
        }
        v.push_back(temp);
        reverse(v.begin(), v.end());
        temp = "";
        for(string t : v)
        {
            temp += t + " ";
        }

        return temp.substr(0, temp.size() - 1);
    }
};