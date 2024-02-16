class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size(), max_freq = n;
        
        // store the frequency of each element in arr
        unordered_map<int, int> mp;
        for(auto it: arr){
            mp[it]++;
        }

        for(auto it: mp){
            max_freq = max(max_freq, it.second);
        }

        // count the frequency of each frequency
        vector<int> countOfFrequencies(max_freq+1, 0);
        for(auto it: mp){
            countOfFrequencies[it.second]++;
        }

        // unique = the current unique elements present
        int unique = mp.size();

        // iterate the countOfFrequencies array
        // Here, i represents the number of times a 
        // frequency appears
        for(int i=1; i<=max_freq; i++){

            // if k < i means we cannot further  
            // decrease the number of unique elements 
            // so return the current uniques present
            if(k < i) return unique;

            // calculate the no. of unique elements
            // we can remove 
            int remove = min(k/i, countOfFrequencies[i]);
            
            // subtract the no. of elements removed 
            // i.e. no. of unique elements we removed * it's frequency
            k -= remove * i;

            // subtract the no. of unique elements removed  
            unique -= remove;
        }

        // if we reach here, it means we have 
        // removed all the unique elements present
        return 0;
    }
};