/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    //Optimal Solution - using slow and fast pointers
    //tc = O(size)
    //sc = O(1)
    int getKthFromLast(Node* head, int k) {
        // code here
        int size = 0;
        
        Node* fast = head;
        for(int i=0; i<k; i++) {
            if(fast == NULL) return -1;
            fast = fast->next;
        }
        
        Node* slow = head;
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow->data;
    }
};