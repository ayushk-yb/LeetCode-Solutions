class StockSpanner {
private:
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        st.push({1e5 + 1, 0});
    }
    
    int next(int price) {
        int curr = st.top().second + 1;
        while(!st.empty() && st.top().first <= price)
        {
            st.pop();
        }

        int ans = curr - st.top().second;
        st.push({price, curr});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */