#include<iostream>
using namespace std;
const int size=1e6;
string s;
int p[size], j, I;
int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
   	cin>>s;
   	for(int i=1;i<s.size();i++)
   	{
   	
   		
   		j=p[i-1];
   		while(1)
   		{
   	    	if(s[j]==s[i])
   	    	{
   	    		p[i]=j+1;
   	    	    break;
   				    		
   	    	}
   	    	else
   	    	{
   	    		if(j==0)
   	    			break;
   	    		j=p[j-1];
   	    	}

   	    	
   	    }
   	}
   	for(int i=0;i<s.size();i++)
   	{
   		cout<<p[i]<<' ';
   	}

	return 0;
}