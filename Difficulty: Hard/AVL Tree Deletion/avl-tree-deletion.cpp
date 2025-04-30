//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

int setHeights(Node* n)
{
	if(!n) return 0;
	n->height = 1 + max( setHeights(n->left) , setHeights(n->right) );
	return n->height;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    setHeights(root);
    return root;
}

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

struct Node* deleteNode(struct Node* root, int data);

int main()
{
	int t;
	cin>>t;
	getchar();

	while(t--)
	{
		string s;
		getline(cin,s);
		Node* root = buildTree(s);
        
		int n;
		cin>> n;
		int ip[n];
		for(int i=0; i<n; i++)
			cin>> ip[i];
        
		for(int i=0; i<n; i++)
		{
			root = deleteNode(root, ip[i]);
			
			if( !isBalancedBST(root) )
				break;
		}
        
		if(root==NULL)
			cout<<"null";
		else
			printInorder(root);
		cout<< endl;
        
		getline(cin,s); // to deal with newline char
	
cout << "~" << "\n";
}
	return 1;
}

// } Driver Code Ends


/* Node is as follows:

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

*/
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
Node* deleteNode(Node* root, int data) {
    // add code here,
    if(!root)
    return NULL;
    else if(root->data<data)
    root->right=deleteNode(root->right,data);
    else if(root->data>data)
    root->left=deleteNode(root->left,data);
    else{
        if(!root->left&&!root->right){
            Node* temp=root;
            delete temp;
            return NULL;
        }
        else if(!root->left&&root->right){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(!root->right&&root->left){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* child=root->right;
            while(child->left)
            child=child->left;
            root->data=child->data;
            root->right=deleteNode(root->right,child->data);
        }
    }
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    int balance=getBalance(root);
    if(balance>1){
        if(getBalance(root->left)>=0)
        return rightrotate(root);
        else{
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }
    }
    else if(balance<-1){
        if(getBalance(root->right)<=0)
        return leftrotate(root);
        else{
            root->right=rightrotate(root->right);
            return leftrotate(root);
        }
    }
    else
    return root;
}