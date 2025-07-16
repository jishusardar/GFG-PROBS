
class Solution {
  public:
    double switchCase(int choice, vector<double> &arr) {
        // code here
        double ans;
        double pi=M_PI;
        switch(choice){
            case 1:
            ans=pi*arr[0]*arr[0];
            break;
            case 2:
            ans=arr[0]*arr[1];
            break;
            default:
            ans=0;
        }
        return ans;
    }
};
