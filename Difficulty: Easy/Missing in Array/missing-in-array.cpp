class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int xor1 = 0;
        for(int i=1; i<=arr.size()+1; i++) {
            xor1 ^= i;
        }
        
        int xor2 = 0;
        for(int i=0; i<arr.size(); i++) {
            xor2 ^= arr[i];
        }
        
        return xor1^xor2;
    }
};