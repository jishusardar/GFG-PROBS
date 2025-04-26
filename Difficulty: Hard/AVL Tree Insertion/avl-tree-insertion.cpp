//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends

/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution {
  public:
    /*You are required to complete this method */
    int getHeight(Node* root)
    {
        if(!root)
        return 0;
        return root->height;
    }
    int getBalance(Node* root)
    {
        return getHeight(root->left)-getHeight(root->right);
    }
    Node* leftrotate(Node* root)
    {
        Node* child=root->right;
        Node* childleft=child->left;
        
        child->left=root;
        root->right=childleft;
        
        root->height=1+max(getHeight(root->left),getHeight(root->right));
        child->height=1+max(getHeight(child->left),getHeight(child->right));
        return child;
    }
    Node* rightrotate(Node* root)
    {
        Node* child=root->left;
        Node* childright=child->right;
        child->right=root;
        root->left=childright;
        root->height=1+max(getHeight(root->left),getHeight(root->right));
        child->height=1+max(getHeight(child->left),getHeight(child->right));
        return child;
    }
    Node* insertToAVL(Node* node, int data) {
        // Your code here
        if(!node)
        return new Node(data);
        
        if(data<node->data)
        node->left=insertToAVL(node->left,data);
        else if(data>node->data)
        node->right=insertToAVL(node->right,data);
        else
        return node;
        node->height=1+max(getHeight(node->left),getHeight(node->right));
        int balance=getBalance(node);
        //L L
        if(balance>1&&data<node->left->data)
        return rightrotate(node);
        // R R
        if(balance<-1&&data>node->right->data)
        return leftrotate(node);
        // L R
        if(balance>1&&data>node->left->data){
            node->left=leftrotate(node->left);
            return rightrotate(node);
        }
        //R L
        if(balance<-1&&data<node->right->data){
            node->right=rightrotate(node->right);
            return leftrotate(node);
        }
        else
        return node;
    }
};


//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends