class Solution {
  public:
    int find(int index,int n,vector<int>&steps){
        if(n==0)
        return 1;
        if(index==0)
        return 0;
        if(steps[index-1]>n)
        return find(index-1,n,steps);
        else
        return find(index,n-steps[index-1],steps)+find(index-1,n,steps);
    }
    int nthStair(int n) {
        //  Code here
        vector<int>steps(2);
        steps[0]=1;
        steps[1]=2;
        return find(2,n,steps);
    }
};