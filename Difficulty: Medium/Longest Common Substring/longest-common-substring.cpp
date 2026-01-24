class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        int ans = 0;
    
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<m+1; j++) {  //if character matched
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                } else {    //if character did not match
                    dp[i][j] = 0;   //because substring is found consecutively
                }
            }
        }
    
        return ans;
    }
};