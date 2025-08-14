// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int count(Node* root)
    {
        if(!root)
        return 0;
        int leftcount=count(root->left);
        int rightcount=count(root->right);
        return 1+leftcount+rightcount;
    }
    void traversal(Node* root,bool& ans,int index,int n)
    {
        if(!root)
        return;
            int leftnode=2*index+1;
            int rightnode=2*index+2;
        if(root->left&&root->right){
            if(leftnode>=n||rightnode>=n)
            ans=0;
            if(root->data<root->left->data||root->data<root->right->data)
            ans=0;
        }
        else if(root->left){
            if(leftnode>=n)
            ans=0;
            if(root->data<root->left->data)
            ans=0;
        }
        else if(root->right){
            if(rightnode>=n)
            ans=0;
            if(root->data<root->right->data)
            ans=0;
        }
        traversal(root->left,ans,leftnode,n);
        traversal(root->right,ans,rightnode,n);
    }
    bool isHeap(Node* tree) {
        // code here
        int totalnode=count(tree);
        bool ans=1;
        traversal(tree,ans,0,totalnode);
        return ans;
    }
};