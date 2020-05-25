#include <bits/stdc++.h>

using namespace std;

string reserveWords(int);
string timeInWords(int h, int m) {
string hour[14]={"o'clock","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen"};
    string words="";
    if(m==0)
    {
        words=hour[h]+" o' clock";
    }
    else if(m==15)
    {
        words="quarter past "+hour[h];
    }
    else if(m==30)
    {
        words="half past "+hour[h];
    }
    else if(m==45)
    {
        words="quarter to "+hour[h+1];
    }
    else if(m<30)
    {
        if(m==1)
        {
            words=reserveWords(m)+ " minute " +"past "+hour[h];
        }
        else
        {
        words=reserveWords(m)+ " minutes " +"past "+hour[h];
        }
    }
    else if(m>30)
    {
        if(m==59)
        {
                words=reserveWords(60-m)+" minute "+"to "+hour[h+1];
        }
        else
        {
        words=reserveWords(60-m)+" minutes "+"to "+hour[h+1];
        }
    }
    else{;}
    return words;
}
string reserveWords(int n)
{
    int a=n%10;
    int b=n/10;
    string str="";
string one[10]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string ONE[9]={"one","two","three","four","five","six","seven","eight","nine"};
    if(b==0)
    {
        str=ONE[n-1];
    }
    else if(b==1)
    {
        str=one[a];
    }
    else if(b==2)
    {
        if(a==0)
        {
            str="twenty";
        }
        else
        {
        str="twenty "+ONE[a-1];
        }
    }
    else{;}
    return str;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}

