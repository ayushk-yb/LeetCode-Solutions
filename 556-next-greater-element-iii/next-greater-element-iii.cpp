class Solution {
public:
    void nextPermutation(string& nums) {
       int brk_pt = -1;
       int n = nums.size();
       for(int i = n - 2; i >= 0; i--)
       {
           if(nums[i] - 'a' < nums[i + 1] - 'a')
           {
               brk_pt = i;
               break;
           }
       }
       if(brk_pt == -1)
       {
           reverse(nums.begin(), nums.end());
           return;
       }
        int i = brk_pt;
        while(i < n - 1)
        {
            if(nums[i + 1]  - 'a'> nums[brk_pt] - 'a')
            {
                i++;
            }
            else
            {
                break;
            }
        }
       swap(nums[i], nums[brk_pt]);
       reverse(nums.begin() + brk_pt + 1, nums.end());
    }

    int stringToInteger(const std::string& str) {
        try {
            size_t pos;
            int result = std::stoi(str, &pos);

            // Check if there are any remaining characters after the conversion
            if (pos != str.size()) {
                std::cerr << "Warning: Input string has additional characters after the valid integer." << std::endl;
                return -1;
            }

            return result;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Integer overflow occurred." << std::endl;
            return -1;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid argument for conversion." << std::endl;
            return -1;
        }
    }

    int nextGreaterElement(int n) {
        string s = to_string(n);
        nextPermutation(s);
        int a = stringToInteger(s);
        if( a == n || a < n)
            return -1;
        return a;
    }
};