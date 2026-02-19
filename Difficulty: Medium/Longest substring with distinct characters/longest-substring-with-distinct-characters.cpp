class Solution {
  public:
    //Optimal Approach - Using two pointers with sliding window
    //tc = O(n)
    //sc = O(256) ~ Constant sc
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int> hash(256, -1);  //not using map, because map might take logn time
        int l=0, r=0;
        int maxLen = 0;
        
        while(r < s.size()) {
            if(hash[s[r]] != -1) {  //char repeated
                if(hash[s[r]] >= l) {   //repeated char first index should be between l & r
                    l = hash[s[r]] + 1; //move l to the next index of repeated char
                }
            }
            
            int len = r - l + 1;
            maxLen = max(maxLen, len);
            
            hash[s[r]] = r; //update or assign index value of char in hash
            r++;
        }
        
        return maxLen;
    }
};
