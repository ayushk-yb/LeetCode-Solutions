class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int mid = 0;
        while(left <= right){
            mid = (left + right) / 2;
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] >= arr[left]){
                if(arr[mid] >= target && arr[left] <= target){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(arr[mid] <= target && arr[right] >= target){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};