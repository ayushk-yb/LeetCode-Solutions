class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freqMap(3, 0);
        int n = nums.size();
        for(int i = 0; i < n; i++){
            freqMap[nums[i]]++;
        }
        int i = 0, currNum = 0;
        while(i < n){
            while(freqMap[currNum] == 0){
                currNum++;
            }
            nums[i] = currNum;
            freqMap[currNum]--;
            i++;
        }
    }
};