//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");

cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node* createBST(int post[],int &size,int &index,int start,int end)
{
    if(index<0||post[index]<start||post[index]>end)
    return NULL;
    Node* temp=new Node(post[index--]);
    temp->right=createBST(post,size,index,temp->data,end);
    temp->left=createBST(post,size,index,start,temp->data);
    return temp;
}
Node *constructTree (int post[], int size)
{
//code here
int index=size-1;
 return createBST(post,size,index,INT_MIN,INT_MAX);
}