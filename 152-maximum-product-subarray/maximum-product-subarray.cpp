class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefixProduct = 1, suffixProduct = 1;
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if(prefixProduct == 0){
                prefixProduct = 1;
            }
            if(suffixProduct == 0){
                suffixProduct = 1;
            }
            prefixProduct *= nums[i];
            suffixProduct *= nums[n - 1 - i];
            maxi = max(maxi, max(prefixProduct, suffixProduct));
        }

        return maxi;
    }
};