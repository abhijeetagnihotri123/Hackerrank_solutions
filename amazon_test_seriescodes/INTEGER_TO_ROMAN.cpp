#include <bits/stdc++.h>
using namespace std;
struct translations
{
    int value;
    string symbol;
};
string intToRoman(int);
int main()
{
    int n;
    cin>>n;
    cout<<intToRoman(n);
    return 0;
}
vector<translations>res;
translations temp;
void push_translation(string symbol,int value)
{   
    temp.symbol = symbol;
    temp.value = value;
    res.push_back(temp);
}
string intToRoman(int num)
{   
    string result = "";
    push_translation("M",1000);
    push_translation("CM",900);
    push_translation("D",500);
    push_translation("CD",400);
    push_translation("C",100);
    push_translation("XC",90);
    push_translation("L",50);
    push_translation("XL",40);
    push_translation("X",10);
    push_translation("IX",9);
    push_translation("V",5);
    push_translation("IV",4);
    push_translation("I",1);
    int i = 0;
    while(i<13 && num > 0)
    {
        int num_trans = num/res[i].value;
        while(num_trans--)
        {
            result += res[i].symbol;
        }
        num = num%res[i].value;
        i++;
    }
    return result;
}