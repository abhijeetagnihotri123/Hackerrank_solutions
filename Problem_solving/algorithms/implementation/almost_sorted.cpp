#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> a) {

    int n = a.size();
    if(n==2)
    {
        if(a[0]<=a[1])
        {
            cout<<"no"<<endl;
        }
        else
        {
            cout<<"yes"<<endl<<"swap "<<1<<" "<<2<<endl;
        }    
    }
    else
    {   
        int i=1;
        vector<int>peak;
        vector<int>valey;
        while(i<n-1)
        {
            if(a[i]>a[i-1] && a[i]>a[i+1]) // Local maxima
            {
                peak.push_back(i);
            }
            if(i==1 && a[i-1] > a[i])
            {
                peak.push_back(i);
            }
            if(a[i]<a[i-1] && a[i]<a[i+1]) // Local minima
            {
                valey.push_back(i);
            }
            if(i==n-2 && a[i+1]<a[i])
            {
                valey.push_back(i);
            }
            i++;
        }
        if(peak.size()==1 && valey.size()==1)
        {
            int l=valey[0];
            int r=peak[0];
            if((l-r)==1 &&(a[l]>a[r-1]))
            {
                cout<<"yes"<<endl<<"swap "<<peak[0]+1<<" "<<valey[0]+1<<endl;
            }
            else if(a[l]>a[r-1] && (l-r)>1)
            {
                cout<<"yes"<<endl<<"reverse "<<peak[0]+1<<" "<<valey[0]+1<<endl;
            }
            else
            {
                cout<<"no"<<endl;
            }
        }
        else if(peak.size()==2 && valey.size()==2)
        {
            int l1,l2,r2;
            l1 = peak[0];
            l2 = peak[1];
            r2 = valey[1];
            if((a[r2]>a[l1-1])&&(a[l1+1]>a[r2])&&(a[l1]<a[r2+1])&&(a[l1]>a[l2]))
            {
                cout<<"yes"<<endl<<"swap "<<l1+1<<" "<<r2+1<<endl;
            }
        }
        else if(peak.size()==0 && valey.size()==0)
        {
            cout<<"no"<<endl;
        }
        else
        {
            cout<<"no";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
