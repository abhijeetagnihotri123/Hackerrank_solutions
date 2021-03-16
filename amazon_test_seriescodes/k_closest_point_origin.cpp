//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 bool compare(const pair<int,int> &a, 
              const pair<int,int> &b) 
{   
  if(a.first==b.first)
    return (a.second < b.second); 
  return a.first<b.first;
} 

vector<vector<int>> kClosest(vector<vector<int>>& , int );

//User code will be pasted here

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<vector<int>> p, res;
        
        for(int i = 0 ; i < n ; ++ i ) {
            vector<int> vec(2);
            cin >> vec[0] >> vec[1];
            p.push_back(vec);
        }
        
        res = kClosest(p, k);
        
        for(int i = 0 ; i < k ; ++ i ) {
            cout << res[i][0] << " " << res[i][1] << " ";
        }
        
        cout << "\n";
        
    }
}// } Driver Code Ends


//User function template for C++

// points : 2-d vector containing the (x, y) points
// K : number of closest points that we need to find 
// return 2d vector containing the k points in increasing order of distance from origin

struct mapping
{
    int distance;
    int index;
    int first;
    int second;
};
bool Compare(mapping m1,mapping m2)
{
    if(m1.distance == m2.distance)
    {
        if(m1.first==m2.first)
        {
            return (m1.second < m2.second);
        } 
        return m1.first<m2.first;
    }
    else
    {
        return (m1.distance < m2.distance);
    }
}
vector<vector<int>>kClosest(vector<vector<int>>&points,int k)
{   
    int n = points.size();
    vector<mapping>v(n);
    for(int i=0;i<n;i++)
    {
        mapping m;
        m.first = points[i][0];
        m.second = points[i][1];
        m.index = i;
        m.distance = m.first*m.first+m.second*m.second;
        v[i] = m;
    }
    sort(v.begin(),v.end(),Compare);
    k = (k>n)?n:k;
    vector<vector<int>>res(k,vector<int>(2,0));
    for(int i=0;i<k;i++)
    {
        res[i][0] = v[i].first;
        res[i][1] = v[i].second;
    }
    return res;
}