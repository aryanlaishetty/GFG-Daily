class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum = 0, maxLen = 0;
        unordered_map<int, int> prefixSumM;    //<prefixSum, index>
    
        for(int i=0; i<arr.size(); i++) {
            sum += arr[i];
            if(sum == k) {
                maxLen = max(maxLen, i+1);
            }
    
            int remaining = sum - k;
            if(prefixSumM.count(remaining)) {
                int len = i - prefixSumM[remaining];
                maxLen = max(maxLen, len);
            }
    
            if(!prefixSumM.count(sum)) {
                prefixSumM[sum] = i;
            }
        }
    
        return maxLen;
    }
};