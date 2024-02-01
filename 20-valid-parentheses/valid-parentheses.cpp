class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        st.push(s[0]);
        int i = 1;
        int n = s.length();
        while(i < n)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            
            else
            {
                if(!st.empty())
                {
                    if(st.top() == '(' && s[i] == ')')
                        st.pop();
                    else if(st.top() == '{' && s[i] == '}')
                        st.pop();
                    else if(st.top() == '[' && s[i] == ']')
                        st.pop();
                    
                    else
                        return false;
                }
                else
                    return false;
            }
            i++;
        }
        return st.empty();
    }
};