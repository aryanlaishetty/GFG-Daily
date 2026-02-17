class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for(int i=0; i<n; i++) {
            if(i > 0 && arr[i] == arr[i-1]) continue; //no consecutive same elements

            int j = i+1;
            int k = n-1;

            while(j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if(sum < target) {   
                    j++;
                } else if(sum > target) {
                    k--;
                } else {    //sum == target
                    ans.push_back({arr[i], arr[j], arr[k]});
                    j++;    
                    k--;
                    while(j < k && arr[j] == arr[j-1]) j++;   //no consecutive same elements
                    while(j < k && arr[k] == arr[k+1]) k--;   //no consecutive same elements
                }
            }
        }
        
        return !ans.empty();    //if array is not empty then triplet for target is found
    }
};