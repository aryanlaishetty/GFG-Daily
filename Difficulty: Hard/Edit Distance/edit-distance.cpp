class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
        for(int j=0; j<m+1; j++) {  //0th row initialize - insert 
            dp[0][j] = j;
        }
    
        for(int i=0; i<n+1; i++) {  //0th col initialize - delete
            dp[i][0] = i;
        }
    
        //bottom up fill
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<m+1; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 0 + dp[i-1][j-1];    //0 represents no. of operations when char matches
                } else {
                                            //insert    delete      replace
                    dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);  
                }
            }
        }
        
        return dp[n][m];
    }
};