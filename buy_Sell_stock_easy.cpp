/*
Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

//method 1 - bruteForce
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = 0;
        for(int i=0;i<prices.size()-1;i++) {
            int buy = prices[i];
            for(int j=i+1;j<prices.size();j++) {
                if(buy < prices[j]) {
                    maxPrice = max(maxPrice,prices[j]-buy);
                }
            }
        }
        return maxPrice;
    }
};
//method 2 - o(n) continuosly update buy by comparing
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = 0;
        int buy = prices[0];
        for(int i=1;i<prices.size();i++) {
            if(prices[i] < buy) {
                buy = prices[i];
            } else {
                maxPrice = max(maxPrice,prices[i]-buy);
            }
        }
        return maxPrice;
    }
};
