class Solution {
public:
    int happySum(int n)
    {   
        int ans = 0;
        while(n > 0)
        {
            int rem = n % 10;
            ans += rem * rem;
            n = n / 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        unordered_set<int> st;
        while(n != 1 && st.count(n) == 0)
        {
            st.insert(n);
            n = happySum(n);
        }

        if(n == 1)
            return true;
        
        return false;
    }
};