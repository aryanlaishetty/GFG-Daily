class Solution {
  public:
    //Optimal Approach using two pointers
    //tc = O(n) + O(nlogn)
    //sc = O(1)
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        int left=0, right=arr.size()-1;
        
        while(left < right) {
            if(arr[left] + arr[right] == target) {
                return true;
            } else if(arr[left] + arr[right] > target) {
                right--;    //sum decreases
            } else {    //sum < target
                left++; //sum increases
            }
        }
        
        return false;
    }
};