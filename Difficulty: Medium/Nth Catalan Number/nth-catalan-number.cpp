class Solution {
  public:
    // Function to find the nth catalan number.
    int findCatalan(int n) {
        // code here
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;  //base case
    
        for(int i=2; i<=n; i++) {   //picking ith catalan
            for(int j=0; j<i; j++) {    //calculation ith catalan - 0 to i
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
    
        return dp[n];
    }
};