class StockSpanner {
    vector<int> stock;
    stack<int> stk;

public:
    StockSpanner() {
        stock.push_back(INT_MAX);
        stk.push(0);
    }
    
    int next(int price) {
        int i = stock.size();
        stock.push_back(price);

        if (stock[stk.top()] > price) {
            stk.push(i);
            return 1;
        }

        while (stock[stk.top()] <= price) {
            stk.pop();
        }
        
        int j = stk.top();
        
        stk.push(i);

        return i - j;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */