class Solution {
public:
    string findDifferentBinaryString(vector<string>& A) {
        int n = A.size();
        unordered_set<int> s;
        for (auto &n : A) {
            s.insert(stoi(n, 0, 2));
        }
        for (int i = 0; i <= n; ++i) {
            if (s.count(i)) continue;
            string ans;
            for (int j = 0; j < n; ++j) {
                ans += '0' + (i & 1);
                i >>= 1;
            }
            reverse(begin(ans), end(ans));
            return ans;
        }
        return "";        
    }
};