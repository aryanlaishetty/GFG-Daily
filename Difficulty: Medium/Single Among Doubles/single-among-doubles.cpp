// User function template for C++
class Solution {
  public:
    int search(int n, int arr[]) {
        // code
        int answer = 0;
        for(int i=0; i<n; i++) {
            answer ^= arr[i];
        }
        return answer;
    }
};