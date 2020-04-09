class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int n = prices.size();
        if (n == 1) 
            return 0; 
        int i = 0; 
        while (i < n - 1) { 
            while ((i < n - 1) && (prices[i + 1] <= prices[i])){
                i++;                 
            } 
            
            if (i == n - 1) 
                break; 
            
            int buy = i++;
            
            while ((i < n) && (prices[i] >= prices[i - 1])) {
                i++;                 
            }
            
            result += (prices[i-1] - prices[buy]);
        } 
        return result;
    }
};