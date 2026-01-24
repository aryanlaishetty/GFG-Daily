class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<long long>> dp(n+1, vector<long long>(sum+1, 0));

        for(int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum; j++) {
                if(coins[i-1] <= j) {   //valid
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];  //include + exclude
                } else {    //invalid
                    dp[i][j] = dp[i-1][j];  //exclude
                }
            }
        }

        return (int)dp[n][sum];
    }
};