class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> mp;
        stack<int> st;
        st.push(-1);
        for(int i = n2 - 1; i >= 0; i--)
        {
            while(st.top() != -1 && nums2[i] > nums2[st.top()])
            {
                st.pop();
            }

            if(st.top() != -1)
                mp[nums2[i]] = nums2[st.top()];
            else
                mp[nums2[i]] = -1;
            st.push(i);
        }

        vector<int> ans(n1);
        for(int i = 0; i < n1; i++)
        {
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};