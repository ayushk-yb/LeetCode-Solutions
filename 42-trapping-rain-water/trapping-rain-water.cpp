class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxLeft = 0, maxRight = 0;
        int water = 0;
        int left = 0, right = n - 1;
        while(left <= right){
            if(height[left] < height[right]){
                maxLeft = max(maxLeft, height[left]);
                water += maxLeft - height[left];
                left++;
            }
            else{
                maxRight = max(maxRight, height[right]);
                water += maxRight - height[right];
                right--;
            }
        }

        return water;
    }
};