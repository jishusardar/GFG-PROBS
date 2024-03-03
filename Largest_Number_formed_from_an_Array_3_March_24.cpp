static bool a(string x,string y)
	{
	    string x1=x+y;
	    string x2=y+x;
	    return x1>x2;
	}
	string printLargest(int n, vector<string> &arr) {
	    // code here
	    string ans;
	    sort(arr.begin(),arr.end(),a);
	    for(int i=0;i<n;i++)
	    ans+=arr[i];
	    return ans;
	    
	    
	}
