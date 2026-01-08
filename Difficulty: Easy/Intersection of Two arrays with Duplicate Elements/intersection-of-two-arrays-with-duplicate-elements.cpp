class Solution {
  public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> s;
        vector<int> ans;

        for(int el : a) {
            s.insert(el);
        }

        for(int el : b) {
            if(s.find(el) != s.end()) {
                ans.push_back(el);
                s.erase(el);
            }
        }
        
        return ans;
    }
};