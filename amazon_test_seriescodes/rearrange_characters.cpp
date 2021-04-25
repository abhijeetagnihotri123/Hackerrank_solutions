#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    struct Node
    {
        char ch;
        int freq;
        bool operator<(const Node& k) const
        {
            return freq < k.freq;
        }
    };
    string rearrangeString(string str)
    {
        vector<int>v(26,0);
        for(char c : str)
        {
            v[c-'a']++;
        }
        priority_queue<Node>pq;
        for(int i=0;i<26;i++)
        {
            if(v[i]>0)
            {
                char ch = (char)(i+97);
                Node temp;
                temp.ch = ch;
                temp.freq = v[i];
                pq.push(temp);
            }
        }
        v.clear();
        Node t1,t2;
        string s = "";
        while(pq.size() > 1)
        {
            t1 = pq.top();
            pq.pop();
            t2 = pq.top();
            pq.pop();
            //cout<<"("<<t1.ch<<","<<t1.freq<<")"<<"("<<t2.ch<<","<<t2.freq<<")";
            char ch1 = t1.ch;
            char ch2 = t2.ch;
            s += ch1;
            s += ch2;
            t1.freq--;
            t2.freq--;
            if(t1.freq > 0)
            {
                pq.push(t1);
            }
            if(t2.freq > 0)
            {
                pq.push(t2);
            }
        }
        t1 = pq.top();
        if(t1.freq > 1)
        {   
            s = "";
        }
        else
        {   
            if((s.length()+1) == str.length())
            {
                char ch1 = t1.ch;
                s += ch1;
            }
        }
        return s;
    }
};

int checker(string str, string pat)
{
    int freq[26];
    for(int i=0;i<26;i++)
        freq[i]=0;
    if(str.length()!=pat.length())
        return 0;
    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-97]--;
        if(pat[i]<97 || pat[i]>122)
            return 0;
        freq[pat[i]-97]++;
    }
    for(int i=0;i<26;i++)
        if(freq[i]!=0)
            return 0;
    for(int i=0;i<pat.length()-1;i++)
        if(pat[i]==pat[i+1])
            return 0;
    return 1;
}
int main()
{
    int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str,ret;
	    cin>>str;
	    Solution ob;
	    ret = ob.rearrangeString(str);
	    cout << checker(str, ret) << endl;
	}
    return 0;
}
