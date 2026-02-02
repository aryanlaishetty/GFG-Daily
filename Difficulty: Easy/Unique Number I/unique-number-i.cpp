class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int answer = 0;
        for(int i=0; i<arr.size(); i++) {
            answer ^= arr[i];
        }
        return answer;
    }
};