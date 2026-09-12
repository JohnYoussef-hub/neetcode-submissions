class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0;
        int maxProfit = 0;

        while(r < prices.size()){
            int profit = prices[r] - prices[l];
            if(profit < 0) l++;
            else{
                maxProfit = ::max(profit, maxProfit);
                r++;
            } 
        }

        return maxProfit;

    }
};
