class Solution {
  public:
    //Optimal Approach - using mergeSort, finding inversions during merge step
    //tc = O(nlogn)
    //sc = O(n)
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low; //starting of left half
        int right = mid+1;  //starting of right half
        
        int count = 0;
        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) {    //left element is smaller
                temp.push_back(arr[left]);
                left++;
            } else {    //right element is smaller
                temp.push_back(arr[right]);
                count += mid - left + 1;    //mid is last index of left half array
                right++;
            }
        }
        
        while(left <= mid) {    //left half is remaining
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= high) {  //right half is remaining
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=low; i<=high; i++) {  //copy elements from temp array to original array
            arr[i] = temp[i-low];
        }
        
        return count;
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        int count = 0;
        if(low >= high) return count;
        int mid = low + (high - low)/2;
        count += mergeSort(arr, low, mid);    //left half
        count += mergeSort(arr, mid+1, high);    //right half
        count += merge(arr, low, mid, high);    //merge left half and right half
        return count;
    }
    
    int inversionCount(vector<int> &arr) {
        // Code Here
        return mergeSort(arr, 0, arr.size()-1);
    }
};