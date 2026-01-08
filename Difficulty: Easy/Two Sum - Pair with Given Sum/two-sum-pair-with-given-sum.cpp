class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_map<int, int> m;  //<arr[i], i>
        
        for(int i=0; i<arr.size(); i++) {
            int compliment = target - arr[i];
            
            if(m.count(compliment)) {
                return true;
            }
            
            m[arr[i]] = i;
        }
        
        return false;
    }
};