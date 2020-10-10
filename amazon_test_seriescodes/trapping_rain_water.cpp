#include<bits/stdc++.h>

using namespace std;
int max_min(int &a,int &b,bool mode)
{
    if(mode)
    {
        return a>=b?a:b;
    }
    else
    {
        return a<=b?a:b;
    }
}
int trappingWater(int a[], int n){
    
    int *lm,*rm;
    int total_water = 0;
    lm = new int[n];
    rm = new int[n];
    lm[0]=a[0];
    rm[n-1]=a[n-1];
    for(int i=1;i<n;i++)
    {
        lm[i]=max_min(lm[i-1],a[i],true);
    }
    for(int i=n-2;i>=0;i--)
    {
        rm[i]=max_min(rm[i+1],a[i],true);
    }
    for(int i=0;i<n;i++)
    {
        int water = max_min(lm[i],rm[i],false);
        total_water += water-a[i];
    }
    delete(lm);
    delete(rm);
    return total_water;
}
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}