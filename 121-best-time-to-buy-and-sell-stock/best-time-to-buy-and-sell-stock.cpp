class Solution {
public:
    void solve(int i, int n, vector<int> &prices, int &minPrice, int &maxProfit)
    {
        if(i == n)
            return;
        
        if(prices[i] < minPrice)
            minPrice = prices[i];
        
        if((prices[i] - minPrice) > maxProfit)
            maxProfit = prices[i] - minPrice;
        
        solve(i + 1, n, prices, minPrice, maxProfit);
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;
        int minPrice = prices[0];
        int maxProfit = INT_MIN;
        solve(1, n, prices, minPrice, maxProfit);

        return maxProfit;
    }
};