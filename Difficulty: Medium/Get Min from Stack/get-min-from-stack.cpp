//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
class Solution {
  public:
    Node* top;
    Node* mini;
    Solution() {
        // code here
        top=NULL;
        mini=NULL;
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(top==NULL){
            top=new Node(x);
            mini=new Node(x);
        }
        else{
        Node* temp=new Node(x);
        temp->next=top;
        top=temp;
        int minimum=min(x,mini->data);
        Node* tempn=new Node(minimum);
        tempn->next=mini;
        mini=tempn;
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(top==NULL)
        return;
        top=top->next;
        mini=mini->next;
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(top==NULL)
        return -1;
        return top->data;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(mini==NULL)
        return -1;
        return mini->data;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends