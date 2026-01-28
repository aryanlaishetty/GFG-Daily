class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int totalSum = 0;
        for(int el : arr) {
            totalSum += el;
        }
    
        int n = arr.size();
        int W = totalSum / 2;
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<W+1; j++) {
                if(arr[i-1] <= j) {
                    dp[i][j] = max(arr[i-1] + dp[i-1][j-arr[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    
        int group1Sum = dp[n][W];
        int group2Sum = totalSum - group1Sum;
    
        return abs(group1Sum - group2Sum);
    }
};
