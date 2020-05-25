#include <bits/stdc++.h>
using namespace std;
bool nextPermutation(string&);
int main()
{  
   int T;
   cin>>T;
   while(T--)
   {
       string str;
       cin>>str;
       bool val=nextPermutation(str);
       if(val==true)
       {
           cout<<str<<endl;
       }
       else
       {
           cout<<"no answer"<<endl;
       }
       
   }   
   return 0;
}
bool nextPermutation(string &s)
{
    int i = s.length()-1;
    while(i>0 && s[i-1]>=s[i])
    {
        i--;
    }
    if(i<=0)
    {
        return false;
    }
    int j=s.length()-1;
    while(s[j]<=s[i-1])
    {
        j--;
    }
    char temp=s[i-1];
    s[i-1]=s[j];
    s[j]=temp;
    j=s.length()-1;
    while(i<j)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
    return true;
}

