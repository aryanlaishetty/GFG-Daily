class Solution {
  public:
    //Optimal solution - using recursion, based on pick and non pick element appraoch
    //tc = O(2^t + k), k = average length of every combination generated
    //sc = O(k * x), x = total number of combinations
    void findComb(int idx, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        if(idx == arr.size()) {
            if(target == 0) ans.push_back(ds);
            return;
        }
        
        //pick
        if(arr[idx] <= target) {
            ds.push_back(arr[idx]);
            findComb(idx, target-arr[idx], arr, ans, ds);
            ds.pop_back();
        }
        
        //non pick
        findComb(idx+1, target, arr, ans, ds);
    }
    
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, target, arr, ans, ds);
        return ans;
        
    }
};