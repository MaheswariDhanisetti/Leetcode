class StockSpanner {
public:

    stack<int>st;
    
    vector<int>v;

    int cnt = 0;

    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int res = 1;

        while(!st.empty() and  v[st.top()] <= price ){
            st.pop();
        }

        if(!st.empty()){
            res = cnt-st.top();
        }
        else{
            res = cnt+1;
        }

        v.push_back(price);
        st.push(cnt);

        cnt++;

        return res;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */