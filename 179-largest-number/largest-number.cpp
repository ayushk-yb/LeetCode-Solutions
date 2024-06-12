class Solution {
public:
    static bool comp(int a, int b){
        string num1 = to_string(a), num2 = to_string(b);
        return num1 + num2 > num2 + num1;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ans += to_string(nums[i]);
        }
        if(ans[0] == '0'){
            return "0";
        }

        return ans;
    }
};