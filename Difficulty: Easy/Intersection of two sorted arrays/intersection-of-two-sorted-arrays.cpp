class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        // code here
        //Brute force approach
        //tc = O(nlogn)
        //sc = O(n)
        unordered_set<int> s;
        vector<int> ans;

        for(int el : arr1) {
            s.insert(el);
        }

        for(int el : arr2) {
            if(s.find(el) != s.end()) {
                ans.push_back(el);
                s.erase(el);
            }
        }
        
        return ans;
    }
};