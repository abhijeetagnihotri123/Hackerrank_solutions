#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<int>NewestOnTop;
stack<int>OldestOntop;
void Enqueue(int);
void Dequeue();
int print();
void shiftstack(void);
int main()
{
    int q;
    cin>>q;
    int i;
    int x;
    while(q--)
    {
        cin>>i;
        switch(i)
        {
        case 1:
            cin>>x;
            Enqueue(x);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            cout<<print()<<endl;
        }
    }
    return 0;
}
void Enqueue(int n)
{
    NewestOnTop.push(n);
}
void Dequeue()
{
    shiftstack();
    OldestOntop.pop();
}
int print()
{
    shiftstack();
    return (OldestOntop.top());
}
void shiftstack(void)
{
    if(OldestOntop.empty())
    {
        while(!NewestOnTop.empty())
        {
            OldestOntop.push(NewestOnTop.top());
            NewestOnTop.pop();
        }
    }
}

