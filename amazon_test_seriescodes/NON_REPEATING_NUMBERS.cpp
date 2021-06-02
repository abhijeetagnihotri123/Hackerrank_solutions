#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int>r(2,0);
        int XOR = 0;
        int set_bit;
        for(int x : nums)
        {
            XOR = XOR ^ x;
        }
        set_bit = XOR & ~(XOR-1); // getting the kth bit this bit is actually the rightmost bit of the XOR
        for(int x : nums)
        {
            if(x & set_bit)
            {
                r[0] = r[0] ^ x;
            }
            else
            {
                r[1] = r[1] ^ x;
            }
        }
        return r;
    }
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}