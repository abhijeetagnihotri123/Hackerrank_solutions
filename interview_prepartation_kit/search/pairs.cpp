#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int binsearch(vector<int>&,int,int,int);
int pairs(int k, vector<int> arr) {
    
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int c=0;
    for(int i=0;i<n-1;i++)
    {
        if(binsearch(arr,i,n-1,arr[i]+k)==1)
        {
            c++;
        }
    }
    return c;
}
int binsearch(vector<int>&a,int beg,int last,int ele)
{
    int mid;
    int f=0;
    while(beg<=last)
    {
        mid=(beg+last)/2;
        if(a[mid]==ele)
        {
            f=1;
            break;
        }
        else if(a[mid]<ele)
        {
            beg=mid+1;
        }
        else
        {
            last=mid-1;
        }
    }
    return f;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
