/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    // bool compare(map<int, int> m1, map<int, int> m2) {
    //     return m1.first < m2.first;
    // }
    
    vector<int> topView(Node *root) {
        // code here
        queue<pair<Node*, int>> q;  //(node, HD)
        map<int, int> m;    //(HD, root->data)
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<Node*, int> curr = q.front();
            q.pop();
            
            Node* currNode = curr.first;
            int currHD = curr.second;
            
            if(m.count(currHD) == 0) {
                m[currHD] = currNode->data;
            }
            
            if(currNode->left != NULL) {
                pair<Node*, int> left = make_pair(currNode->left, currHD-1);
                q.push(left);
            }
            
            if(currNode->right != NULL) {
                pair<Node*, int> right = make_pair(currNode->right, currHD+1);
                q.push(right);
            }
        }
        
        // sort(m.begin(), m.end(), compare);
    
        vector<int> ans;
        
        for(auto i : m) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};