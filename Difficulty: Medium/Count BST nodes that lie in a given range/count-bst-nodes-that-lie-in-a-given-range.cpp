/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverse(Node* root,int l,int h,int &ans)
    {
        if(!root)
        return;
        if(root->data>=l&&root->data<=h)
        ans++;
        traverse(root->left,l,h,ans);
        traverse(root->right,l,h,ans);
    }
    int getCount(Node *root, int l, int h) {
        // your code here
        int ans=0;
        traverse(root,l,h,ans);
        return ans;
        
    }
};