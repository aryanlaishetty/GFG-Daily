class Solution {
  public:
    
    
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<int> rowVals;
        
        int ans = 1;
        rowVals.push_back(ans);
        
        for(int i=1; i<n; i++) {
            ans *= (n-i);
            ans /= i;
            rowVals.push_back(ans);
        }
        
        return rowVals;
    }
};
