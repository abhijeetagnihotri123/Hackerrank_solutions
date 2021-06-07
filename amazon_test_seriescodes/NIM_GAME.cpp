/*
Given a number N for given number of stones 
two players can draw 1 or 2 or 3 stones at a time
out of two players which one will win
*/
#include <iostream>
using namespace std;

bool player1(int n)
{
    return (n&1 || n&2 || n&3);
}
int main()
{   
    int n;
    cin>>n;
    if(player1(n))
    {
        cout<<"Player 1 wins"<<endl;
    }
    else
    {
        cout<<"Player 2 wins"<<endl;
    }
    return 0;
}