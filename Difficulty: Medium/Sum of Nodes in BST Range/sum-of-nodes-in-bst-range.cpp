/*
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
    void traverse(Node* root,int l,int r,int &ans)
    {
        if(!root)
        return;
        if(root->data>=l&&root->data<=r)
        ans+=root->data;
        traverse(root->left,l,r,ans);
        traverse(root->right,l,r,ans);
    }
    int nodeSum(Node* root, int l, int r) {
        // code here
        int ans=0;
        traverse(root,l,r,ans);
        return ans;
    }
};
