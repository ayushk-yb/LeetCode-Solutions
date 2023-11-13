class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.length();
        priority_queue<char, vector<char>, greater<char>> q; 
        for(int i = 0; i < n; i++)
        {
            if(vowels.find(s[i]) != vowels.end())
            {
                q.push(s[i]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(vowels.find(s[i]) != vowels.end())
            {
                s[i] = q.top();
                q.pop();
            }
        }
        return s;
    }
};