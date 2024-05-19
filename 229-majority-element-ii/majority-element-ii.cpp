class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int countOne = 0, countTwo = 0;
        int candidateOne = -1, candidateTwo = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(candidateOne == nums[i]){
                countOne++;
            }
            else if(candidateTwo == nums[i]){
                countTwo++;
            }
            else if(countOne == 0){
                countOne++;
                candidateOne = nums[i];
            }
            else if(countTwo == 0){
                countTwo++;
                candidateTwo = nums[i];
            }
            else{
                countOne--;
                countTwo--;
            }
        }

        countOne = 0, countTwo = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == candidateOne){
                countOne++;
            }
            else if(nums[i] == candidateTwo){
                countTwo++;
            }
        }

        vector<int> result;
        if(countOne > n / 3){
            result.push_back(candidateOne);
        }
        if(countTwo > n / 3){
            result.push_back(candidateTwo);
        }

        return result;
    }
};