/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:

    Node* lca(Node* root, int n1, int n2) {
        //  code here
        if(root == NULL) {
            return NULL;
        }

        if(root->data == n1 || root->data == n2) {
            return root;
        }

        Node* leftLCA = lca(root->left, n1, n2);
        Node* rightLCA = lca(root->right, n1, n2);

        if(leftLCA != NULL && rightLCA != NULL) {
            return root;
        }

        return leftLCA == NULL ? rightLCA : leftLCA; 
    }
};