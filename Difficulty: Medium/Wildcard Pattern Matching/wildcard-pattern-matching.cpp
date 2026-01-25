class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size();   //string size
        int m = pat.size();   //pattern size

        vector<vector<int>> dp(n+1, vector<int>(m+1, false));
        dp[0][0] = true;    //when s and p both are empty than p can be converted into s

        for(int j=1; j<m+1; j++) {  //0th row, when text is empty
            if(pat[j-1] == '*') {
                dp[0][j] = dp[0][j-1];  
            } else {    //when char is some alphabet or '?'
                dp[0][j] = false;
            }
        }

        //Bottom up fill DP table
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<m+1; j++) {
                if(txt[i-1] == pat[j-1] || pat[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(pat[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};