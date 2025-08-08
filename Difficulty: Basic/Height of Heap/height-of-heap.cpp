 class Solution {
  public:
    int find(int n)
    {
        if(n==1)
        return 0;
        return 1+find(n/2);
    }
    int heapHeight(int n, int arr[]) {
        // code here
        if(n==1)
        return 1;
        return find(n);
    }
};