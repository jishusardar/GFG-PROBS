//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int Burn(Node* root,int target,int& ans)
    {
        if(!root)
        return 0;
        if(root->data==target)
        return -1;
        int left=Burn(root->left,target,ans);
        int right=Burn(root->right,target,ans);
        if(left<0){
            ans=max(ans,abs(left)+right);
            return left-1;
        }
        if(right<0){
            ans=max(ans,abs(right)+left);
            return right-1;
        }
        return 1+max(left,right);
    }
    Node* find(Node* root,int target)
    {
        if(!root)
        return NULL;
        if(root->data==target)
        return root;
        return find(root->left,target);
        return find(root->right,target);
    }
    int height(Node* root)
    {
        if(!root)
        return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int minTime(Node* root, int target) {
        // code here
        int ans=INT_MIN;
        int temp=Burn(root,target,ans);
        if(ans==INT_MIN)
        ans=temp;
        Node* BurnNode=find(root,target);
        return max(ans,height(BurnNode)-1);
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends