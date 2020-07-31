#include <bits/stdc++.h>
using namespace std;

char *encode(char *src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		char str[10000];
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

char *encode(char *src)
{     
    string s = "";
    int c = 0;
    int n = strlen(src);
    int i = 0;
    int j = 0;
    while(i<n-1)
    {
        j = i;
        s+=src[i];
        c = 0;
        while(src[j] == src[j+1] && j<n-1)
        {
            j++;
        }
        if(i == j)
        {   
            c = 1;
            i++;
        }
        else
        {
            c = j-i+1;
            i = j+1;
        }
        string s1 = to_string(c);
        s += s1;
    }
    if(i == n-1)
    {
        n = 1;
        string s1 = to_string(n);
        s+=src[i];
        s+=s1;
    }
    i = 0;
    n = s.length();
    for(i=0;i<n;i++)
    {
        src[i]=s[i];
    }
    src[n]='\0';
    return src;
}   