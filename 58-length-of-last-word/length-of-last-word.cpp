class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = 0;
        int count = 0, last = 0;
        while(i < n){
            if(s[i] == ' ')
            {
                if(count != 0)
                    last = count;
                count = 0;
            }
            else
                count++;
            i++;
        }
        return count != 0 ? count : last;
    }
};