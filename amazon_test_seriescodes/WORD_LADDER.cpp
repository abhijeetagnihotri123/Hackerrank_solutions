#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordLadderLength(string start, string target, vector<string>& wordList) {
    if(start == target)
      return 0;
    set<string>D;
    for(string x : wordList)
    {
        D.insert(x);
    }
    if (D.find(target) == D.end())
        return 0;
    int level = 0, wordlength = start.size();
    queue<string> Q;
    Q.push(start);
    while (!Q.empty()) {

        ++level;

        int sizeofQ = Q.size();
        for (int i = 0; i < sizeofQ; ++i) {

            string word = Q.front();
            Q.pop();

            for (int pos = 0; pos < wordlength; ++pos) {

                char orig_char = word[pos];

                for (char c = 'a'; c <= 'z'; ++c) {
                    word[pos] = c;

                    if (word == target)
                        return level + 1;
                    if (D.find(word) == D.end())
                        continue;
                    D.erase(word);
                    Q.push(word);
                }
                word[pos] = orig_char;
            }
        }
    }

    return 0;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}