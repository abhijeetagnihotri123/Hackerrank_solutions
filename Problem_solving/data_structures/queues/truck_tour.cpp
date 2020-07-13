#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>PP(n,vector<int>(2,0));
    queue<int>q;
    map<int,bool>m;
    for(int i=0;i<n;i++)
    {
        cin>>PP[i][0]>>PP[i][1];
        q.push(i);
    }
    int index,min_index;
    min_index = 2147483647;
    long long int current_amount,distance;
    current_amount = 0;
    int counter=0;
    while(!q.empty())
    {
        index = q.front();
        current_amount+=PP[index][0];
        distance=PP[index][1];
        counter++;
        if(current_amount<distance)
        {
            m[index]=true;
            min_index=index+1;
            current_amount=0;
            q.pop();
            q.push(index);
        }
        else if(counter > n)
        {
            break;
        }
        else
        {
            if(index < min_index && !m[index])
            {
                min_index=index;
            }
            current_amount-=distance;
            q.pop();
        }
    }
    cout<<min_index;
    return 0;
}
