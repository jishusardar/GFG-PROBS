class Solution {
  public:
  bool prime(int n)
  {
      if(n<2)
      return 0;
      for(int i=2;i<=sqrt(n);i++)
      {
          if(n%i==0)
          return 0;
      }
      return 1;
  }
    vector<int> getPrimes(int n) {
        vector<int>ans(2,-1);
        int start=0,end=n;
        while(start<=end)
        {
            if(prime(start)+prime(end)==2)
            {
                ans[0]=start;
                ans[1]=end;
                return ans;
            }
            else
            start++,end--;
                
        }
        return ans;
    }
};
