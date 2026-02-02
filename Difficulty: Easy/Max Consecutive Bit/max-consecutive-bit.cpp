class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int maxOne = 0, tempOne = 0, maxZero = 0, tempZero = 0;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == 1) {
                tempOne++;
                tempZero = 0;
            } else if (arr[i]==0) {
                tempZero++;
                tempOne = 0;
            }
            
            maxOne=max(maxOne, tempOne);
            maxZero=max(maxZero, tempZero);
        }
        
        return max(maxOne, maxZero);
    }
};