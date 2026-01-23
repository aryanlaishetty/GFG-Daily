class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

        for(int i=1; i<n+1; i++) {
            for(int j=1; j<capacity+1; j++) {
                int itemWt = wt[i-1];
                int itemVal = val[i-1];
    
                if(itemWt <= j) {   //j = capacity
                    dp[i][j] = max(itemVal + dp[i][j-itemWt], dp[i-1][j]);   //max(included, excluded)
                } else {
                    dp[i][j] = dp[i-1][j];  //excluded
                }
            }
        }
    
        return dp[n][capacity];
    }
};