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
    //adjusting heights
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
    //adjusting new heights
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    child->height=1+max(getHeight(child->left),getHeight(child->right));
    return child;
}
    Node* insert(Node* root,int val)
    {
        if(!root)
    return new Node(val);
    //check the val goes on left
    if(val<root->data)
    root->left=insert(root->left,val);
    //check the val goes on right
    else if(val>root->data)
    root->right=insert(root->right,val);
    //if duplicate return the root;
    else
    return root;
    
    //initialize height of the nodes
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    //check balancing
    int balance=getBalance(root);
    //check if it is left left
    if(balance>1&&val<root->left->data)
    return rightrotate(root);
    //check if it is left right
    else if(balance>1&&val>root->left->data){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    //check if its is right right
    else if(balance<-1&&val>root->right->data)
    return leftrotate(root);
    //check if its is right left 
    else if(balance<-1&&val<root->right->data){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    else
    return root;
    }
    Node* insertToAVL(Node* node, int data) {
        // Your code here
        return insert(node,data);
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