class Solution {
  public:
    int _01KnapsackByTabulation(vector<int> val, vector<int> wt, int W, int n) {   //O(n*W)
    
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<W+1; j++) {
                int itemWt = wt[i-1];
                int itemVal = val[i-1];
    
                if(itemWt <= j) {   //j = capacity
                    dp[i][j] = max(itemVal + dp[i-1][j-itemWt], dp[i-1][j]);   //max(included, excluded)
                } else {
                    dp[i][j] = dp[i-1][j];  //excluded
                }
            }
        }
    
        return dp[n][W];
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        return _01KnapsackByTabulation(val, wt, W, n);
        
    }
};