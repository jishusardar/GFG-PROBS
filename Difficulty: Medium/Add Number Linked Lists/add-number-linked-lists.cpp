//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to add two numbers represented by linked list
    Node* reverse(Node* head,Node* pre)
    {
        if(head==NULL)
        return pre;
        Node* fut=head->next;
        head->next=pre;
        return reverse(fut,head);
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        if(num1->data==0){
            num1=reverse(num1->next,NULL);
        }
        else if(num1->data!=0){
             num1=reverse(num1,NULL);
        }
        if(num2->data==0){
            num2=reverse(num2->next,NULL);
        }
        else if(num2->data!=0){
            num2=reverse(num2,NULL);
        }
        Node* ans=new Node(0);
        Node* temp=ans;
        int rem=0;
        while(num1!=NULL&&num2!=NULL){
        int num=num1->data+num2->data+rem;
        temp->next=new Node(num%10);
        temp=temp->next;
        rem=num/10;
        num1=num1->next;
        num2=num2->next;
        }
        while(num1!=NULL){
            int num=num1->data+rem;
            temp->next=new Node(num%10);
            temp=temp->next;
            rem=num/10;
            num1=num1->next;
        }
        while(num2!=NULL){
            int num=num2->data+rem;
            temp->next=new Node(num%10);
            temp=temp->next;
            rem=num/10;
            num2=num2->next;
        }
        while(rem){
            int num=rem;
            temp->next=new Node(num%10);
            rem=num/10;
        };
        ans=reverse(ans->next,NULL);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends