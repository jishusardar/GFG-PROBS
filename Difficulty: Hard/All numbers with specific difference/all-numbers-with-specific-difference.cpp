class Solution {
  public:
    int find(int n){
        int m=log(n)+1;
        int ans=0;
        while(m--){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int getCount(int n, int d) {
        // code here
        int ans=0;
        bool flag=0;
        int start=1,end=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mid-find(mid)>=d){
                ans=mid;
                flag=1;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        if(n>d){
            if(flag)
            return n-ans+1;
        }
        return 0;
        
        
    }
};