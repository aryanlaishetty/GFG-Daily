/*
Structure of the node of the binary tree is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
*/
class Solution {
  public:
    // function should return level of the target node
    int helper(struct Node *node, int target, int currLevel) {
        if(node == NULL) {
            return 0;
        }    
        
        if(node->data == target) {
            return currLevel;
        }
        
        int left = helper(node->left, target, currLevel+1);    //left
        int right = helper(node->right, target, currLevel+1);   //right
        
        return left+right;
    }
    
    int getLevel(struct Node *node, int target) {
        // code here
        return helper(node, target, 1);
    }
};