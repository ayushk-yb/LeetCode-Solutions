class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indexS(200, -1);
        vector<int> indexT(200, -1);
        
        int len = s.length();
        
        if(len != t.length()) { 
            return false;
        }
        
        for(int i = 0; i < len; i++) { 
            if(indexS[s[i]] != indexT[t[i]]) 
                return false; 
            
            indexS[s[i]] = i; 
            indexT[t[i]] = i;
        }
        
        return true; 
    }
};