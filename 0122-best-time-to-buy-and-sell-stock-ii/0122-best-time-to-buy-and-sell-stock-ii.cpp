class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        for(int i=0;i<prices.size()-1;i++){
            while(i<prices.size()-1 && prices[i+1]>prices[i]){
                sum+=abs(prices[i]-prices[i+1]);
                i++;
            }
        }
        return sum;
    }
};