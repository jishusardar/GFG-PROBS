class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        priority_queue<long long>q1;
        priority_queue<long long>q2;
        for(long long i=0;i<K1;i++)
        q1.push(A[i]);
        for(long long i=K1;i<N;i++){
            if(A[i]<q1.top()){
                q1.pop();
                q1.push(A[i]);
            }
        }
        for(long long i=0;i<K2-1;i++)
        q2.push(A[i]);
        for(long long i=K2-1;i<N;i++){
            if(A[i]<q2.top()){
                q2.pop();
                q2.push(A[i]);
            }
        }
        long long ans=0;
        while(!q1.empty()){
            ans+=q1.top();
            q1.pop();
        }
        while(!q2.empty()){
            ans-=q2.top();
            q2.pop();
        }
        return ans*-1;
        
    }
};