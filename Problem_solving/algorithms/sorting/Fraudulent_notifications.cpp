#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.

int twicemedian(vector<int>&,vector<int>&,int&);
int activityNotifications(vector<int> A, int d) {
    
    vector<int>count(201,0);
    int n=A.size();
    int alerts=0;
    for(int i=0;i<d;i++)
    {
        count[A[i]]++;
    }
    for(int i=d;i<n;i++)
    {
        int median=twicemedian(A,count,d);
        if(median<=A[i])
        {
            alerts++;
            //cout<<median<<" "<<A[i]<<endl;
        }
        count[A[i-d]]--;
        count[A[i]]++;
    }
    return alerts;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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

int twicemedian(vector<int>&A,vector<int>&count,int &d)
{   
    vector<int>cumulative_frequency(count);
    int median=0;
    for(int i=1;i<cumulative_frequency.size();i++)
    {
        cumulative_frequency[i]+=cumulative_frequency[i-1];
    }
    if(d%2==0)
    {
        int first=d/2;
        int second=first+1;
        int i=0;
        int a,b;
        while(i<201)
        {
            if(first<=cumulative_frequency[i])
            {
                a=i;
                break;
            }
            i++;
        }
        while(i<201)
        {
            if(second<=cumulative_frequency[i])
            {
                b=i;
                break;
            }
            i++;
        }
        median=a+b;
    }
    else
    {
        int first=d/2+1;
        int i=0;
        while(i<201)
        {
            if(first<=cumulative_frequency[i])
            {
                median=2*i;
                break;
            }
            i++;
        }
    }
    return median;
}

