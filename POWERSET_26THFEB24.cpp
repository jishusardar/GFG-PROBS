void pw(string s,int index,vector<string> &ans,string temp)
	    {
	        if(index==s.length())
	        {
	            if(temp.length())
	            ans.push_back(temp);
	            return;
	        }
	        pw(s,index+1,ans,temp);
	        temp+=s[index];
	        pw(s,index+1,ans,temp);
	    }
		vector<string> AllPossibleStrings(string s)
		{
		    vector<string> ans;
		    string temp;
		    pw(s,0,ans,temp);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
