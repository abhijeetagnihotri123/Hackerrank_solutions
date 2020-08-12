#include <bits/stdc++.h>
using namespace std;

string convertToWords(long);

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		long int n;
		cin>>n;
		cout << convertToWords(n) << endl; 
	}
}
string one[] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ", "eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen " };

string ten[] = { "", "", "twenty ", "thirty ", "forty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety " };
string convert(int n,string s)
{
    string str="";
    if(n>19)
    {
        str+=ten[n/10]+one[n%10];
    }
    else
    {
        str+=one[n];
    }
    if(n>0)
    {
        str+=s;
    }
    return str;
}
string convertToWords(long n)
{   
    string result = "";
    result += convert(n/10000000,"crore ");
    result += convert((n/100000)%100,"lakh ");
    result += convert((n/1000)%100,"thousand ");
    result += convert((n/100)%10,"hundred ");
    if(n>100 && n%100 != 0)
    {
        result+="and ";
    } 
    result += convert(n%100,"");
    return result;
}