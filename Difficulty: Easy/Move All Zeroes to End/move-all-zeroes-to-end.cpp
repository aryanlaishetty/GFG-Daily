class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size();

        int j = -1;
        for(int i=0; i<n; i++) {
            if(arr[i] == 0) {
                j = i;  //Here, j points at element 0
                break;
            }
        }

        if(j == -1) return; //if no zeroes exist in nums

        for(int i=j+1; i<n; i++) {
            if(arr[i] != 0) {  //as j is non zero
                swap(arr[i], arr[j]); //swap non zero element with zero element
                j++;
            }
        } 
    }
};