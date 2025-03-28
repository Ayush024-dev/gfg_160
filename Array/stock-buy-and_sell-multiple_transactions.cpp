//2 Approach:- if you can buy a stock, then either you will buy the stock or not. Same if you can sell a stock, then either you will sell a stock or not.
//code for App 1-
class Solution {
  public:
    int solve(int idx, int buy, vector<int> &arr, vector<vector<int>> &dp){
        int n=arr.size();
        
        if(idx==n) return 0;
        
        if(dp[idx][buy]!=-1) return dp[idx][buy]; 
        
        if(buy){
            return max(-1 * arr[idx] + solve(idx+1, 0, arr,dp) , solve(idx+1, buy, arr,dp));
        }
        
        
        
        
        return dp[idx][buy] = max(arr[idx]+solve(idx+1, 1, arr,dp), solve(idx+1, buy, arr,dp));
        //Approach 1 ends
        // int npick=solve(idx+1, buy, arr, dp);  //Approach 2 begins: either you are not doing anything on a day or you are doing something (either buying or selling, whichever you can do)
        
        // int pick=0;
        
        // if(buy==1){
        //     pick=-1 * arr[idx] + solve(idx+1, 0, arr, dp);
        // }
        // else pick=arr[idx] + solve(idx+1, 1, arr, dp);
        
        // return dp[idx][buy]= max(npick, pick);
        //Approach 2 ends
    }
    int maximumProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int> (3,-1));
        
        return solve(0, 1, prices,dp);
    }
};
