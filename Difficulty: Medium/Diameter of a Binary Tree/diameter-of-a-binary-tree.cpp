/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        if(root == NULL) {
            return 0;
        }
        
        int leftHt = height(root->left);
        int rightHt = height(root->right);
        
        int currHt = max(leftHt, rightHt) + 1;
        
        return currHt;
    }
    
    int diameter(Node* root) {
        // code here
        if(root == NULL) {
            return 0;
        }
        
        int currDiam = height(root->left) + height(root->right);
        int leftDiam = diameter(root->left);
        int rightDiam = diameter(root->right);

        return max(currDiam, max(leftDiam, rightDiam));
    }
};