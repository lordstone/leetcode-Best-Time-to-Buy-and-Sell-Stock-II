class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        if(prices.size() == 2) return prices[0]<prices[1] ? prices[1]-prices[0]: 0;
        vector<int> maxpro(prices.size(), 0);
        maxpro[0] = 0;
        maxpro[1] = prices[0]<prices[1] ? prices[1]-prices[0]: 0;
        for(int i = 2;i < prices.size();i++){
            /*
            for(int j = 1; j < i; j++){
                if(maxpro[j-1] + prices[i] - prices[j] > maxpro[i]) maxpro[i] = maxpro[j-1] + prices[i] - prices[j];
            }//end for j
            */
            if(maxpro[i-1] + prices[i] - prices[i-1] > maxpro[i]) maxpro[i] = maxpro[i-1] + prices[i] - prices[i-1];
            if(maxpro[i-1]>maxpro[i]) maxpro[i] = maxpro[i-1];
        }//end for i
        return maxpro[prices.size() - 1];
    }
};
