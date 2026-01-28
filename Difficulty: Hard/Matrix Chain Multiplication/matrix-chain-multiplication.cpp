class Solution {
  public:
    int mcmByMemoization(vector<int> arr, int i, int j, vector<vector<int>> &dp) { //TC = O(n^3)
        if(i == j) {    //single matrix
            return 0;   //ops for multiplying single matrix is 0
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
    
        int ans = INT_MAX;
    
        for(int k=i; k<j; k++) {    //this loop will create partitions and divide matrices into two groups
    
            //first group - (i, k)
            int cost1 = mcmByMemoization(arr, i, k, dp);
            
            //second group - (k+1, j)
            int cost2 = mcmByMemoization(arr, k+1, j, dp);
    
            //current partition cost
            int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
            ans = min(ans, currCost);
        }
    
        return dp[i][j] = ans;    
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return mcmByMemoization(arr, 1, n-1, dp);
    }
};