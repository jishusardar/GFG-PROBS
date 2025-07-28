class Solution {
  public:
    void printn(int i,int n)
    {
        if(i==n+1)
        return;
        cout<<i<<" ";
        printn(i+1,n);
    }
    void printNos(int n) {
        // Code here
        printn(1,n);
    }
};