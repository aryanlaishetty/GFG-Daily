class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int k = 0, i = 0;
        
        for(i=0; i<arr.size()-1; i++) {
            if(arr[i] > arr[i+1]) {
                break;
            }
        }
        
        while(i>=0) {
            i--;
            k++;
        }
        
        return arr.size() == k ? 0 : k;
    }
};
