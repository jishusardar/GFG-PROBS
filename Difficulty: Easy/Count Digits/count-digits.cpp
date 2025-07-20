class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int count=0;
        int temp=n;
        while(n!=0){
            int rem=n%10;
            n/=10;
            if(rem!=0&&temp%rem==0)
            count++;
        }
        return count;
    }
};