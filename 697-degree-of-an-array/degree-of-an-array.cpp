class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        unordered_map<int, int> firstSeen;

        int maxFreq = INT_MIN;
        int minLength = INT_MAX;

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if (firstSeen.find(nums[i]) == firstSeen.end()) {
                firstSeen[nums[i]] = i;
            }
            if (freq[nums[i]] == maxFreq) {
                minLength = min(minLength, i - firstSeen[nums[i]] + 1);
            } else if (freq[nums[i]] > maxFreq) {
                maxFreq = freq[nums[i]];
                minLength = i - firstSeen[nums[i]] + 1;
            }
        }

        return minLength;
    }
};