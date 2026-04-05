
class Solution {
  public:
    bool checkf4(int n){
        while(n!=0){
            int rem=n%10;
            if(rem==4)
            return 1;
            n/=10;
        }
        return 0;
    }
    int find(int n){
        if(n==1)
        return 0;
        if(checkf4(n))
        return 1+find(n-1);
        else
        return find(n-1);
    }
    int countNumberswith4(int n) {
        // code here
        return find(n);
    }
};
