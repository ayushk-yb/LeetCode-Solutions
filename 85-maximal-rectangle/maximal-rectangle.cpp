class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n){
        // Your code here
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);
        
        for(int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int> arr, int n){
        // Your code here
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> n = nextSmallerElement(heights, size);
        vector<int> p = prevSmallerElement(heights, size);

        int area = INT_MIN;
        for(int i = 0; i < size; i++)
        {
          int l = heights[i];
          if(n[i] == -1)
          {
            n[i] = size;
          }
          int b = n[i] - p[i] - 1;
          int area_curr = l * b;
          area = max(area, area_curr);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(m, 0);
        for(int i = 0;i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};