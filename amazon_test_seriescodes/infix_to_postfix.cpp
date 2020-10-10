#include <bits/stdc++.h>
using namespace std;

bool isoperand(char);
bool isoperator(char); 
int prec(char);
string infix_to_postfix(string&);
int main()
{   
    string s;
    cout<<"Enter the prefix expression to be converted\n";
    cin>>s;
    cout<<infix_to_postfix(s);
    return 0;
}
string infix_to_postfix(string &s)
{
    std::stack<char> st; 
    st.push('N'); 
    int l = s.length(); 
    string ns=""; 
    for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
        ns+=s[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == '(') 
          
        st.push('('); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(s[i] == ')') 
        { 
            while(st.top() != 'N' && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
               ns += c; 
            } 
            if(st.top() == '(') 
            { 
                char c = st.top(); 
                st.pop(); 
            } 
        } 
          
        //If an operator is scanned 
        else{ 
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(s[i]); 
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(st.top() != 'N') 
    { 
        char c = st.top(); 
        st.pop(); 
        ns += c; 
    }
    return ns;
}
int prec(char c)
{   
    int p;
    switch(c)
    {
        case '^':
            p = 3;
            break;
        case '/':
            p = 2;
            break;
        case '*':
            p = 2;
            break;
        case '+':
            p = 1;
            break;
        case '-':
            p = 1;
            break;
        default:
            p = -1;
            break; 
    }
    return p;
}
bool isoperand(char ch)
{
    return ((ch>='a' && ch<='z') || (ch>='A') || ch<='Z');
}
bool isoperator(char ch)
{
    return (ch=='^' || ch == '*' || ch == '/' || ch == '+' || ch == '-');
}