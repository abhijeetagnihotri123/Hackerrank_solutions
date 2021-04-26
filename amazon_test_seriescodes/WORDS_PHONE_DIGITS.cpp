#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution{
    public:
    vector<string>translations;
    void generage_translations()
    {
        translations.push_back("");
        translations.push_back("");
        translations.push_back("abc");
        translations.push_back("def");
        translations.push_back("ghi");
        translations.push_back("jkl");
        translations.push_back("mno");
        translations.push_back("pqrs");
        translations.push_back("tuv");
        translations.push_back("wxyz");
    }
    void generate_words(int a[],int curr_digit,char word[],int n,vector<string>&res)
    {
        if(curr_digit == n)
        {
            string s = string(word);
            res.push_back(s);
            return;
        }
        for(int i=0;i<translations[a[curr_digit]].length();i++)
        {
            word[curr_digit] = translations[a[curr_digit]][i];
            generate_words(a,curr_digit+1,word,n,res);
            if(a[curr_digit] == 0 || a[curr_digit] == 1)
            {
                return;
            }
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        generage_translations();
        vector<string>res;
        char word[N+1];
        word[N]='\0';
        generate_words(a,0,word,N,res);
        return res;
    }
};

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
} 