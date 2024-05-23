class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        int maxi = height[0];
        left[0] = maxi;
        for(int i = 1; i < n; i++){
            maxi = max(maxi, height[i]);
            left[i] = maxi;
        }
        maxi = height[n - 1];
        right[n - 1] = maxi;
        for(int i = n - 2; i >= 0; i--){
            maxi = max(maxi, height[i]);
            right[i] = maxi;
        }

        int water = 0;
        for(int i = 1; i < n - 1; i++){
            int level = min(left[i - 1], right[i + 1]);
            if(height[i] < level){
                water += level - height[i];
            }
        }

        return water;
    }
};