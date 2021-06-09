#include<bits/stdc++.h>
using namespace std;

/*
    * Leet code has plenty of variants on this problem,have a glance in it, IMPORTANT
    * Time complexity- O(n),
    * Space Complexity - O(1),
*/

double BuyAndSellStockOnce(vector<double> &nums)
{
    double min_price_so_far=numeric_limits<double>::max(),max_profit=0;
    for(auto x:nums)
    {
        const double max_profit_sell_today=x-min_price_so_far;
        max_profit=max(max_profit,max_profit_sell_today);
        min_price_so_far=min(min_price_so_far,x);
    }
    return max_profit;
}

/*
    * variant
    * geeksforgeeks - https://www.geeksforgeeks.org/longest-subarray-with-all-elements-same/#:~:text=Approach%3A%20The%20idea%20is%20to,subarray%20is%20equal%20to%201.
    * 
    * 
*/
int find(vector<int> nums)
{
    int n=nums.size();
    int i=0,final_ans=0;
    while(i<n)
    {
        int ans=0;
        while(i+1 < n && nums[i]==nums[i+1])
        {
            ans++;i++;
        }
        final_ans=max(final_ans,ans);
    }
    return final_ans;
}

/*  
    * Buy and Sell Stock Twice
    * 
*/
int BuyAndSellTwice(vector<int> nums)
{
    int minPriceSoFar=numeric_limits<int>::max(),maxProfit=0;
    int forwardProfits[nums.size()];
    for(int i=0;i<nums.size();i++)
    {
        int todayProfit=nums[i]-minPriceSoFar;
        minPriceSoFar=min(minPriceSoFar,nums[i]);
        maxProfit=max(maxProfit,todayProfit);
        forwardProfits[i]=maxProfit;
    }
    int BackWardProfits[nums.size()];
    int maxPriceSoFar=numeric_limits<int>::min();
    for(int i=nums.size()-1;i>0;i--)
    {
        maxPriceSoFar=max(maxPriceSoFar,nums[i]);
        maxProfit=max(maxProfit,forwardProfits[i-1]+maxPriceSoFar-nums[i]);
    }
    return maxProfit;
}
int main()
{
    vector<int> ar;
}