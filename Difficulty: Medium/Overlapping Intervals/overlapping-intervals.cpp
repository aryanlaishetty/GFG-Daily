class Solution {
  public:
    //Optimal Approach
    //tc = O(nlogn + n)
    //sc = O(n)
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());   

        for(int i=0; i<arr.size(); i++) {
            if(ans.empty() || ans.back()[1] < arr[i][0]) {
                ans.push_back(arr[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }

        return ans;
    }
};