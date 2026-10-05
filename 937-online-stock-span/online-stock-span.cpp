class StockSpanner {
public:
    vector<int> prices;
    stack<int> s;

    StockSpanner() {

    }
    
    int next(int price) {
        prices.push_back(price);
        int i=prices.size()-1;
        
        while (!s.empty() && prices[s.top()]<=price){
            s.pop();
        }

        int ans; 
    
        if (s.empty()){
            ans=i+1;
        }
        else{
            ans=i-s.top();
        }

        s.push(i);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */