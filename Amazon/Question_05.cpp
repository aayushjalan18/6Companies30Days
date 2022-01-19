
#include <bits/stdc++.h>
using namespace std;

class Trie
{
    private :
        bool isEndofWord;
        Trie* character[26];
    
    public :
        Trie()
        {
            this->isEndofWord = false;
            for(int i=0; i<26; i++)
                this->character[i] = nullptr;
        }
        void insert(string word)
        {
            Trie* curr = this;
            for(auto w : word)
            {
                if(curr->character[w-'a'] == nullptr)
                    curr->character[w-'a'] = new Trie();
                curr = curr->character[w-'a'];
            }
            curr->isEndofWord = true;
        }
        void printWords(Trie* curr, string S, vector<string>& ans)
        {
            if(curr->isEndofWord)
                ans.push_back(S);
            for(int i=0; i<26; i++)
            {
                if(curr->character[i] != nullptr)
                {
                    S.push_back(char(i+'a'));
                    printWords(curr->character[i],S,ans);
                    S.pop_back();
                }
            }
        }
        vector<vector<string>> search(string word)
        {
            string S;
            vector<vector<string>> res;
            Trie* curr = this;
            for(auto w : word)
            {
                S.push_back(w);
                if(curr == nullptr || curr->character[w-'a'] == nullptr)
                {
                    curr = nullptr;
                    res.push_back({"0"});
                }
                else 
                {
                    curr = curr->character[w-'a'];
                    vector<string> ans;
                    printWords(curr,S,ans);
                    res.push_back(ans);
                }
            }
            return res;
        }
};

vector<vector<string>> solve(int n, vector<string> contact, string s)
{
	Trie tr;
	for(int i=0; i<n; i++)
		tr.insert(contact[i]);
	return tr.search(s);
}

int main() 
{
	
	int n;
	cin >> n;
	
	vector<string> contact(n);
	for(int i=0; i<n; i++)
		cin >> contact[i];
	
	string s;
	cin >> s;
	
	vector<vector<string>> res = solve(n, contact, s);
	
	for(auto r : res)
	{
		for(auto s : r)
			cout << s << ' ';
		cout << '\n';
	}
	
	return 0;
}
