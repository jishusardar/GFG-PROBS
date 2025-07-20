class Solution {
  public:
    int gcd(int a,int b)
    {
        if(b==0)
        return a;
        return gcd(b,a%b);
    }
    int lcm(int a,int b)
    {
        return (a/gcd(a,b))*b;
    }
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        vector<int>ans(2);
        ans[1]=gcd(a,b);
        ans[0]=lcm(a,b);
        return ans;
    }
};